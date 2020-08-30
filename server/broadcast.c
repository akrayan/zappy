/*
** broadcast.c for  in /home/laurent/rendu/PSU_2016_zappy/server
**
** Made by laurent
** Login   <laurent@epitech.net>
**
** Started on  Thu Jun 29 10:38:20 2017 laurent
** Last update Mon Jul  3 21:21:46 2017 laurent
*/

#include "../include/server.h"

void		check_good_dir(int *dir, char tgt_dir)
{
  if (tgt_dir == 0)
    return ;
  if (tgt_dir == 2)
    (*dir) += 2;
  if (tgt_dir == 1)
    (*dir) += 4;
  if (tgt_dir == 4)
    (*dir) += 6;
  (*dir) = (((*dir) - 1) % 8) + 1;
}

int             get_dir(int xa, int ya, int xb, int yb)
{
  static int    kval[3][3] = {{0, 5, 1},
			      {7, 6, 8},
			      {3, 4, 2}};
  int           x;
  int           y;

  x = 0;
  y = 0;
  if (xa > xb)
    x = 1;
  else if (xa < xb)
    x = 2;
  else
    x = 0;
  if (ya > yb)
    y = 1;
  else if (ya < yb)
    y = 2;
  else
    y = 0;
  return (kval[x][y]);
}

int		search(t_server *s, t_player *src, t_player *tgt)
{
  int		x_max;
  int		y_max;
  int		dir;

  x_max = s->dim_x;
  y_max = s->dim_y;
  get_distance(src, tgt, &x_max, &y_max);
  dir = get_dir(src->x, src->y, x_max, y_max);
  check_good_dir(&dir, tgt->dir);
  return (dir);
}

void		my_broadcast(t_server *s, t_player *p, char **arg)
{
  t_player	*tmp;
  char		*s1;
  char		*l;
  int		i;

  tmp = s->l_player;
  asprintf(&s1, "message %d,", search(s, p, tmp));
  i = 0;
  while (arg[++i])
    {
      (i == 0) ? asprintf(&l, "%s", arg[i]) : asprintf(&l, " %s", arg[i]);
      s1 = (char *)realloc(s1, sizeof(char) * (strlen(s1) + strlen(l) + 2));
      s1 = strncat(s1, l, strlen(s1) + strlen(l));
    }
  asprintf(&l, "\n");
  s1 = (char *)realloc(s1, sizeof(char) * (strlen(s1) + strlen(l) + 2));
  s1 = strncat(s1, l, strlen(s1) + strlen(l));
  while (tmp)
    {
      if (tmp->fd_type == FD_client && tmp->fd != p->fd && arg[1])
	tmp->msg = s1;
      tmp = tmp->next;
    }
  rec_gui(&s->l_player, s1);
}
