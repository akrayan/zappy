/*
** begin_incantation.c for  in /home/laurent/rendu/PSU_2016_zappy/server
**
** Made by laurent
** Login   <laurent@epitech.net>
**
** Started on  Mon Jul  3 11:37:33 2017 laurent
** Last update Mon Jul  3 14:42:46 2017 laurent
*/

#include "../include/server.h"

void            send_b_incantation_to_gui(t_server *s, t_player *p)
{
  char          *s1;
  char          *l;
  t_player      *tmp;

  tmp = s->l_player;
  asprintf(&s1, "pic %d %d %d %d", p->x, p->y, p->lvl, p->fd);
  while (tmp)
    {
      if (tmp->fd_type == FD_client && tmp->x == p->x &&
	  tmp->y == p->y && tmp->lvl == p->lvl)
	{
	  asprintf(&l, " %d", p->fd);
	  s1 = (char *)realloc(s1, sizeof(char) * (strlen(s1) + strlen(l) + 2));
	  s1 = strncat(s1, l, strlen(s1) + strlen(l));
	}
      tmp = tmp->next;
    }
  asprintf(&l, "\n");
  s1 = (char *)realloc(s1, sizeof(char) * (strlen(s1) + strlen(l) + 2));
  s1 = strncat(s1, l, strlen(s1) + strlen(l));
  rec_gui(&s->l_player, s1);
}

void			begin_incantation2(t_server *s, t_player *p, int i)
{
  t_player		*tmp;

  tmp = s->l_player;
  while (tmp)
    {
      if (tmp->fd_type == FD_client && tmp->x == p->x &&
	  tmp->y == p->y && tmp->lvl == p->lvl)
	{
	  if (i == 0)
	    {
	      tmp->time_action = (300.f / s->args->freq) * 1000000;
	      dprintf(tmp->fd, "Elevation underway\n");
	      tmp->if_inc = 0;
	    }
	}
      tmp = tmp->next;
    }
}

int                     begin_incantation(t_server *s, t_player *p)
{
  static char           stones[7][8] = {{1, 1, 1, 0, 0, 0, 0, 0},
					{2, 2, 1, 1, 1, 0, 0, 0},
					{3, 2, 2, 0, 1, 0, 2, 0},
					{4, 4, 1, 1, 2, 0, 1, 0},
					{5, 4, 1, 2, 1, 3, 0, 0},
					{6, 6, 1, 2, 3, 0, 1, 0},
					{7, 6, 2, 2, 2, 2, 2, 1}};
  int                   nb_p;
  int                   i;

  i = 0;
  if ((nb_p = check_nb_good_players(s, p)) < stones[p->lvl - 1][1] ||
      (check_stones_on_case(s, stones[p->lvl - 1], p->x, p->y) == false))
    i = 1;
  begin_incantation2(s, p, i);
  p->if_inc = 1;
  return (i);
}
