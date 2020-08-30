/*
** take_obj.c for  in /home/laurent/rendu/PSU_2016_zappy
**
** Made by laurent
** Login   <laurent@epitech.net>
**
** Started on  Mon Jun 26 16:05:28 2017 laurent
** Last update Mon Jul  3 15:42:04 2017 laurent
*/

#include "../include/server.h"

void    send_take_obj_gui(t_server *s, t_player *p, int y)
{
  char  *s1;
  char  *l;

  asprintf(&s1, "pgt %d %d\n", p->fd, y);
  asprintf(&l, "pin %d %d %d %d %d %d %d %d %d %d\n",
	   p->fd, p->x, p->y, p->inventory[0],
	   p->inventory[1], p->inventory[2], p->inventory[3],
	   p->inventory[4], p->inventory[5], p->inventory[6]);
  s1 = (char *)realloc(s1, sizeof(char) * (strlen(s1) + strlen(l) + 2));
  s1 = strncat(s1, l, strlen(s1) + strlen(l));
  asprintf(&l, "bct %d %d %d %d %d %d %d %d %d\n", p->x, p->y,
	   s->map[p->y * s->dim_x + p->x][0],
	   s->map[p->y * s->dim_x + p->x][1],  s->map[p->y * s->dim_x  + p->x][2],
	   s->map[p->y * s->dim_x + p->x][3],
	   s->map[p->y * s->dim_x + p->x][4],  s->map[p->y * s->dim_x + p->x][5],
	   s->map[p->y * s->dim_x + p->x][6]);
  s1 = (char *)realloc(s1, sizeof(char) * (strlen(s1) + strlen(l) + 2));
  s1 = strncat(s1, l, strlen(s1) + strlen(l));
  rec_gui(&s->l_player, s1);
}

int		take_obj(t_server *server, t_player **p, char *obj)
{
  int		i;
  int		y;

  i = -1;
  y = -1;
  if (!obj)
    return (-1);
  while (++i < 7)
    if (strcasecmp(obj, server->ref_rsrc[i]) == 0)
      y = i;
  if (y == -1)
    return (-1);
   if ((*p)->fd_type == FD_client &&
      server->map[(*p)->y * server->dim_x + (*p)->x][y] > 0)
    server->map[(*p)->y * server->dim_x + (*p)->x][y]--;
  else
    return (-1);
   if (y == 0)
     server->map[rand() % server->dim_y * server->dim_x +
		 rand() % server->dim_x][0]++;
  (*p)->inventory[y]++;
  send_take_obj_gui(server, *p, y);
  return (0);
}
