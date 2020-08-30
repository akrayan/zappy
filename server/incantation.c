/*
** incantation.c for  in /home/laurent/rendu/PSU_2016_zappy/server
**
** Made by laurent
** Login   <laurent@epitech.net>
**
** Started on  Mon Jun 26 19:08:49 2017 laurent
** Last update Sun Jul  2 23:50:10 2017 laurent
*/

#include "../include/server.h"

int    check_nb_good_players(t_server *s, t_player *p)
{
  t_player  *tmp;
  int    nb;

  nb = 0;
  tmp = s->l_player;
  while (tmp)
    {
      if (tmp->fd_type == FD_client && tmp->x == p->x &&
	  tmp->y == p->y && tmp->lvl == p->lvl)
	nb++;
      tmp = tmp->next;
    }
  return (nb);
}

void		regen_case(t_server *s, int x, int y)
{
  int		i;

  i = -1;
  while (++i < 7)
    s->map[y * s->dim_x + x][i] = !(rand() % (s->rare_rsrc[i]))
      ? rand() % 6 : 0;
}

void	send_incantation_to_gui(t_server *s, t_player *p,
				int go_on, t_player *tmp)
{
  char	*s1;
  char	*l;

  asprintf(&s1, "pie %d %d %d\n", p->x, p->y, go_on);
  while (tmp)
    {
      if (tmp->x == p->x && tmp->y == p->y && tmp->lvl == p->lvl
	  && tmp->fd_type == FD_client)
	{
	  asprintf(&l, "plv %d %d\n", p->fd, p->lvl);
	  s1 = (char *)realloc(s1, sizeof(char) * (strlen(s1) + strlen(l) + 2));
	  s1 = strncat(s1, l, strlen(s1) + strlen(l));
	}
      tmp = tmp->next;
    }
  asprintf(&l, "bct %d %d %d %d %d %d %d %d %d\n", p->x, p->y,
	   s->map[p->y * s->dim_x + p->x][0],
	   s->map[p->y * s->dim_x + p->x][1],  s->map[p->y * s->dim_x  + p->x][2],
	   s->map[p->y * s->dim_x + p->x][3],
	   s->map[p->y * s->dim_x + p->x][4],  s->map[p->y * s->dim_x + p->x][5],
	   s->map[p->y * s->dim_x + p->x][6]);
  s1 = (char *)realloc(s1, sizeof(char) * (strlen(s1) + strlen(l) + 2));
  s1 = strncat(s1, l, strlen(s1) + strlen(l));
  rec_gui(&s->l_player, s1);
  send_graphic(s);
}

int    incantation2(t_server *s, t_player *p, t_player *tmp)
{
  s = s;
  while (tmp)
    {
      if (tmp->x == p->x && tmp->y == p->y
	  && tmp->lvl == p->lvl && tmp->fd_type == FD_client)
	{
	  tmp->fd != p->fd ? tmp->lvl++ : 1;
	  tmp->if_inc = 0;
	  dprintf(tmp->fd, "Current level : %d\n",
		  tmp->fd == p->fd ? tmp->lvl+1 : tmp->lvl);
	}
      tmp = tmp->next;
    }
  p->lvl++;
  return (0);
}

int		incantation(t_server *s, t_player *p)
{
  static char		stones[7][8] = {{1, 1, 1, 0, 0, 0, 0, 0},
					{2, 2, 1, 1, 1, 0, 0, 0},
					{3, 2, 2, 0, 1, 0, 2, 0},
					{4, 4, 1, 1, 2, 0, 1, 0},
					{5, 4, 1, 2, 1, 3, 0, 0},
					{6, 6, 1, 2, 3, 0, 1, 0},
					{7, 6, 2, 2, 2, 2, 2, 1}};
  t_player	*tmp;
  t_player	*tmp2;
  int		nb_p;

  tmp = s->l_player;
  tmp2 = s->l_player;
  asprintf(&p->resp, "ko\n");
  if ((nb_p = check_nb_good_players(s, p)) < stones[p->lvl - 1][1] ||
      (check_stones_on_case(s, stones[p->lvl - 1], p->x, p->y) == false))
    {
      send_incantation_to_gui(s, p, 0, tmp2);
      return (0);
    }
  incantation2(s, p, tmp);
  regen_case(s, p->x, p->y);
  send_incantation_to_gui(s, p, 1, tmp2);
  p->resp = NULL;
  return (0);
}
