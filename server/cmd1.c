/*
** cmd1.c for  in /home/laurent/rendu/PSU_2016_zappy
**
** Made by laurent
** Login   <laurent@epitech.net>
**
** Started on  Fri Jun 30 09:20:04 2017 laurent
** Last update Sun Jul  2 23:52:17 2017 laurent
*/

#include "../include/server.h"

int		cmd_fork(t_server *server, t_player *player, char **arg)
{
  char		*send;

  arg = arg;
  player->time_action = (42.f / server->args->freq) * 1000000;
  player->if_fork = 1;
  dprintf(1, "[Player -> %d] : fork demander\n", player->fd);
  asprintf(&send, "pfk %d\n", player->fd);
  rec_gui(&server->l_player, send);
  asprintf(&player->resp, "ok\n");
  return (0);
}

int		cmd_take(t_server *server, t_player *player, char **arg)
{
  player->time_action = (7.f / server->args->freq) * 1000000;
  if (take_obj(server, &player, arg[1]) == 0)
    asprintf(&player->resp, "ok\n");
  else
    asprintf(&player->resp, "ko\n");
  dprintf(1, "[Player -> %d] : take objet demander\n", player->fd);
  return (0);
}

int		cmd_set(t_server *server, t_player *player, char **arg)
{
  player->time_action = (7.f / server->args->freq) * 1000000;
  if (leave_obj(server, &player, arg[1]) == 0)
    asprintf(&player->resp, "ok\n");
  else
    asprintf(&player->resp, "ko\n");
  dprintf(1, "[Player -> %d] : set objet demander\n", player->fd);
  return (0);
}

int		cmd_incantation(t_server *server, t_player *player, char **arg)
{
  arg = arg;
  player->time_action = (300.f / server->args->freq) * 1000000;
  if (begin_incantation(server, player) == 1)
    {
      player->if_inc = 0;
      player->time_action = 0;
      dprintf(player->fd, "ko\n");
    }
  else
    send_b_incantation_to_gui(server, player);
  dprintf(1, "[Player -> %d] : incantation objet demander\n", player->fd);
  return (0);
}

int               cmd_unknow(t_server *server, t_player *player, char **arg)
{
  server = server;
  player = player;
  arg = arg;
  dprintf(player->fd, "ko\n");
  return (0);
}
