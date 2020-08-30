/*
** time.c for  in /home/laurent/rendu/PSU_2016_zappy
**
** Made by laurent
** Login   <laurent@epitech.net>
**
** Started on  Sun Jul  2 15:11:53 2017 laurent
** Last update Mon Jul  3 14:14:44 2017 laurent
*/

#include "../include/server.h"

int		take_food(t_player *player, t_server *server)
{
  if (player->inventory[FOOD] - 1 >= 0)
    {
      player->inventory[FOOD]--;
      player->time_life += (126.f / server->args->freq) * 1000000;
      return (0);
    }
  return (-1);
}

void		check_time_action(t_server *server, t_player **p, double diff)
{
  if ((*p)->time_action > 0)
    {
      if ((*p)->time_action > 0 && (*p)->time_action - diff <= 0)
	{
	  if ((*p)->if_inc == 1)
	    {
	      (*p)->if_inc = 0;
	      incantation(server, (*p));
	    }
	  if ((*p)->if_br == 1)
	    {
	      send_message(server, (*p));
	      (*p)->if_br = 0;
	    }
	  (*p)->resp ? dprintf((*p)->fd, "%s", (*p)->resp) : 1;
	  send_graphic(server);
	  if ((*p)->if_fork == 1)
	    {
	      (*p)->if_fork = 0;
	      create_eggs(&server->l_eggs, (*p)->team, server, (*p));
	    }
	}
      (*p)->time_action -= diff;
    }
}

void		check_time_life(t_server *server, t_player **p)
{
  char		*send;

  if ((*p)->time_life <= 0 && take_food((*p), server) == -1)
    {
      asprintf(&send, "pdi %d\n", (*p)->fd);
      rec_gui(&server->l_player, send);
      send_graphic(server);
      (*p)->team->nb_player--;
      dprintf((*p)->fd, "dead\n");
      (*p)->fd_type = FD_free;
      close((*p)->fd);
    }
}

void		check_time(struct timeval *begin, struct timeval *end,
				   t_server *server)
{
  double	diff;
  t_player	*p;

  (*begin) = (*end);
  p = server->l_player;
  gettimeofday(end, NULL);
  diff = (end->tv_sec * 1000000 + end->tv_usec) -
    (begin->tv_sec * 1000000 + begin->tv_usec);
  while (p)
    {
      if (p->fd_type == FD_client && p->team)
	{
	  p->time_life -= diff;
	  check_time_action(server, &p, diff);
	  check_time_life(server, &p);
	}
      p = p->next;
    }
  hatching_eggs(&server->l_eggs, diff, server);
}
