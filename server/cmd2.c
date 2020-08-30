/*
** cmd2.c for  in /home/laurent/rendu/PSU_2016_zappy
**
** Made by laurent
** Login   <laurent@epitech.net>
**
** Started on  Fri Jun 30 09:20:49 2017 laurent
** Last update Mon Jul  3 08:56:14 2017 Laurent MONFOURNY
*/

#include "../include/server.h"

int             cmd_eject(t_server *server, t_player *player, char **arg)
{
  t_player      *tmp;
  char		*s1;
  char		*l;
  int		i;

  tmp = server->l_player;
  arg = arg;
  i = 0;
  player->time_action = (7.f / server->args->freq) * 1000000;
  asprintf(&s1, "pex %d\n", player->fd);
  while (tmp)
    {
      if (tmp->fd != player->fd && tmp->fd_type == FD_client
	  && tmp->x == player->x && tmp->y == player->y)
	{
	  eject_player(server, &tmp, player->dir, &i);
	  asprintf(&l, "ppo %d %d %d %d\n", tmp->fd, tmp->x, tmp->y, tmp->dir);
	  s1 = (char *)realloc(s1, sizeof(char) * (strlen(s1) + strlen(l) + 2));
	  s1 = strncat(s1, l, strlen(s1) + strlen(l));
	}
      tmp = tmp->next;
    }
  if (i == 0)
    return (-1);
  return (rec_gui(&server->l_player, s1));
}

int               cmd_look(t_server *s, t_player *p, char **arg)
{
  arg = arg;
  p->time_action = (7.f / s->args->freq) * 1000000;
  p->dir == 1 ? look_down(s, p) : p->dir == 2 ?
    look_right(s, p) : p->dir == 3 ?
    look_up(s, p) : p->dir == 4 ? look_left(s, p) : 1;
  rec_gui(&s->l_player, NULL);
  return (0);
}

int               cmd_inventory(t_server *server, t_player *player, char **arg)
{
  int   i;
  char  *l;

  arg = arg;
  player->time_action = (1.f / server->args->freq) * 1000000;
  player->resp = strdup("[");
  dprintf(1, "[");
  i = -1;
  while (++i < 7)
    {
            i != 6 ?
	      asprintf(&l, " %s %d, ", server->ref_rsrc[i], player->inventory[i]) :
	      asprintf(&l, " %s %d ]\n", server->ref_rsrc[i],
		       player->inventory[i]);
	    player->resp = (char *)
	      realloc(player->resp, sizeof(char) *
		      (strlen((player->resp == NULL) ? " " :
			      player->resp) + strlen(l) + 4));
	    player->resp = strncat(player->resp, l, strlen(l));
    }
  return (0);
}

int               cmd_broadcast(t_server *server, t_player *player, char **arg)
{
  player->time_action = (double)(7) / (double)server->args->freq * 1000000;
  if (!arg[1])
    asprintf(&player->resp, "ko\n");
  else
    {
      player->if_br = 1;
      my_broadcast(server, player, arg);
      asprintf(&player->resp, "ok\n");
    }
  printf("Broadcast demander %d \n", player->fd);
  return (0);
}

int               cmd_connect_nbr(t_server *s, t_player *p, char **arg)
{
  dprintf(p->fd, "%d\n", (p->team->nb_max_player - p->team->nb_player));
  if (s && arg)
    return (0);
  return (0);
}
