/*
** cmd.c for cmd.c in /home/rayan/System_Unix/Reseau/PSU_2016_zappy
**
** Made by Rayan
** Login   <raihane.akkache@epitech.eu>
**
** Started on  Fri Jun 16 08:06:11 2017 Rayan
** Last update Sun Jul  2 23:59:38 2017 laurent
*/

#include "../include/server.h"

int		  cmd_forward(t_server *server, t_player *p, char **arg)
{
  char		*send;

  arg = arg;
  p->time_action = (7.f / server->args->freq) * 1000000;
  move_pos(server, &p);
  asprintf(&send, "ppo %d %d %d %d\n", p->fd, p->x, p->y, p->dir);
  rec_gui(&server->l_player, send);
  asprintf(&p->resp, "ok\n");
  return (0);
}

int		  cmd_right(t_server *server, t_player *p, char **arg)
{
  char		*send;

  arg = arg;
  p->time_action = (7.f / server->args->freq) * 1000000;
  ((*p).dir < 4) ? ((*p).dir++) : ((*p).dir = 1);
  asprintf(&send, "ppo %d %d %d %d\n", p->fd, p->x, p->y, p->dir);
  rec_gui(&server->l_player, send);
  asprintf(&p->resp, "ok\n");
  return (0);
}

int		  cmd_left(t_server *server, t_player *p, char **arg)
{
  char		*send;

  arg = arg;
  p->time_action = (7.f / server->args->freq) * 1000000;
  ((*p).dir > 1) ? ((*p).dir--) : ((*p).dir = 4);
  asprintf(&send, "ppo %d %d %d %d\n", p->fd, p->x, p->y, p->dir);
  rec_gui(&server->l_player, send);
  asprintf(&p->resp, "ok\n");
  return (0);
}
