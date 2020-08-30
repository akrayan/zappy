/*
** com_gui.c for  in /home/parallels/rendu/PSU_2016_zappy/server
**
** Made by Parallels
** Login   <laurent.monfourny@epitech.eu>
**
** Started on  Sat Jun 24 11:09:59 2017 Parallels
** Last update Mon Jul  3 08:55:17 2017 Laurent MONFOURNY
*/

#include "../include/server.h"

int            rec_gui(t_player **players, char *send)
{
  t_player      *graphic;

  graphic = (*players);
  while (graphic)
    {
      if (graphic->fd_type == FD_graphique)
	graphic->resp = send;
      graphic = graphic->next;
    }
  return (0);
}

void		send_graphic(t_server *server)
{
  t_player	*gui;

  gui = server->l_player;
  while (gui)
    {
      if (gui->fd_type == FD_graphique && gui->resp != NULL)
	dprintf(gui->fd, "%s", gui->resp);
      gui = gui->next;
    }
}

void		welcome_gui(t_server *s, t_player *p, char **teams)
{
  int           i;
  t_player	*tmp;

  tmp = s->l_player;
  p->x = 0;
  p->y = 0;
  dprintf(p->fd, "msz %d %d\n",  s->args->width, s->args->height);
  dprintf(p->fd, "sgt %d\n", s->args->freq);
  i = -1;
  while (++i < s->dim_x * s->dim_y)
    dprintf(p->fd, "bct %d %d %d %d %d %d %d %d %d\n",
	    i % s->dim_x, i / s->dim_x,
	    s->map[i][0], s->map[i][1], s->map[i][2],
	    s->map[i][3], s->map[i][4], s->map[i][5], s->map[i][6]);
  i = -1;
  if (teams)
    while (teams[++i])
      dprintf(p->fd, "tna %s\n", teams[i]);
  while (tmp)
    {
      if (tmp && tmp->team && tmp->fd_type == FD_client)
	dprintf(p->fd, "pnw %d %d %d %d %d %s\n",
		tmp->fd, tmp->x, tmp->y, tmp->dir, tmp->lvl, tmp->team->name);
      tmp = tmp->next;
    }
}
