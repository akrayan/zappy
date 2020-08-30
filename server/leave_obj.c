/*
** leave_obj.c for  in /home/laurent/rendu/PSU_2016_zappy/server
**
** Made by laurent
** Login   <laurent@epitech.net>
**
** Started on  Mon Jun 26 16:05:33 2017 laurent
** Last update Mon Jul  3 13:59:12 2017 laurent
*/

#include "../include/server.h"

void		send_leave_obj_gui(t_server *s, t_player *p, int y)
{
  char		*send;
  char		*new_line;

  asprintf(&send, "pdr %d %d\n", p->fd, y);
  asprintf(&new_line, "pin %d %d %d %d %d %d %d %d %d %d\n",
	   p->fd, p->x, p->y, p->inventory[0],
	   p->inventory[1], p->inventory[2], p->inventory[3],
	   p->inventory[4], p->inventory[5], p->inventory[6]);
  send = (char *)realloc(send, sizeof(char) *
			 (strlen(send) + strlen(new_line) + 2));
  send = strncat(send, new_line, strlen(send) + strlen(new_line));
  asprintf(&new_line, "bct %d %d %d %d %d %d %d %d %d\n",
	   p->x, p->y, s->map[p->x *  s->dim_x  + p->y][0],
	   s->map[p->y * s->dim_x + p->x][1],  s->map[p->y * s->dim_x + p->x][2],
	   s->map[p->y * s->dim_x + p->x][3],
	   s->map[p->y * s->dim_x + p->x][4],  s->map[p->y * s->dim_x + p->x][5],
	   s->map[p->y * s->dim_x + p->x][6]);
  send = (char *)realloc(send, sizeof(char) *
			 (strlen(send) + strlen(new_line) + 2));
  send = strncat(send, new_line, strlen(send) + strlen(new_line));
  rec_gui(&s->l_player, send);
}

int		leave_obj(t_server *s, t_player **p, char *obj)
{
  int		i;
  int		y;

  i = -1;
  y = -1;
  if (!obj)
    return (-1);
  while (++i < 7)
    {
      if (strcasecmp(obj, s->ref_rsrc[i]) == 0)
	y = i;
    }
  if (y == -1)
    return (-1);
  if ((*p)->inventory[y] - 1 >= 0)
    (*p)->inventory[y]--;
  else
    return (-1);
  s->map[(*p)->y * s->dim_x + (*p)->x][y]++;
  send_leave_obj_gui(s, *p, y);
  return (0);
}

void		play_cmd(t_cmd **cmds, t_server *server, t_player *player)
{
  t_cmd		*cmd;
  t_cmd		*tmp;

  cmd = *cmds;
  if (player->time_action <= 0 && player->fd_type == FD_client
      && player->l_cmd != NULL)
    {
      exec_cmd(player->l_cmd->cmd, server, player);
      tmp = (cmd != NULL) ? cmd->next : cmd;
      *cmds = tmp;
    }
}
