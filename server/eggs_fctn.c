/*
** network.c for network.c in /home/rayan/System_Unix/Reseau/PSU_2016_zappy/server
**
** Made by Rayan
** Login   <raihane.akkache@epitech.eu>
**
** Started on  Wed Jun 14 16:57:01 2017 Rayan
** Last update Sun Jul  2 23:48:11 2017 laurent
*/

#include "../include/server.h"

int		create_eggs(t_eggs **l_eggs, t_team *team,
			    t_server *server, t_player *player)
{
  char		*send;
  t_eggs	*new;
  t_eggs	*tmp;

  tmp = *l_eggs;
  if ((new = malloc(sizeof(t_eggs))) == NULL)
    return (-1);
  team->nb_eggs++;
  new->team = team;
  new->x = player->x;
  new->id = 0;
  new->y = player->y;
  new->can_connect = 0;
  new->time_hatching = (double)(600.f / server->args->freq) * 1000000;
  new->next = (*l_eggs);
  if ((*l_eggs))
    while (tmp->next)
      tmp = tmp->next;
  new->id = tmp->id + 1;
  (*l_eggs) = new;
  asprintf(&send, "enw %d %d\n", 1, player->fd);
  rec_gui(&server->l_player, send);
  send_graphic(server);
  return (0);
}

int		hatching_eggs(t_eggs **l_eggs, double diff, t_server *server)
{
  char		*send;
  t_eggs	*tmp;

  if (!(tmp = (*l_eggs)))
    return (-1);
  tmp->time_hatching -= diff;
  if (!tmp->next && tmp->time_hatching <= 0 && tmp->can_connect == 0)
    {
      printf("Team %s can connect one more\n", tmp->team->name);
      asprintf(&send, "eht %d\n", tmp->id);
      rec_gui(&server->l_player, send);
      send_graphic(server);
      tmp->team->nb_max_player++;
      tmp->can_connect = 1;
      return (0);
    }
  else if (!tmp->next)
    return (-1);
  hatching2(l_eggs, diff, server);
  return (0);
}

int		add_fork_player(t_player *player, t_team *teams)
{
  t_team	*tmp2;
  t_team	**tmp;

  tmp2 = teams;
  while (tmp2)
    {
      if (strcmp(player->team->name, teams->name) == 0)
      	{
      	  tmp = &tmp2;
      	  (*tmp)->nb_max_player++;
      	  return (1);
      	}
      tmp2 = tmp2->next;
    }
  return (-1);
}

t_eggs		*search_eggs_hatching(t_team *team, t_eggs *l_eggs)
{
  t_eggs	*tmp;

  tmp = l_eggs;
  while (tmp)
    {
      if (tmp->can_connect == 1 && strcmp(tmp->team->name, team->name) == 0)
	return (tmp);
      tmp = tmp->next;
    }
  return (tmp);
}

int		remove_egg(t_eggs **l_eggs, t_eggs *egg)
{
  t_eggs	*tmp;
  t_eggs	*save;

  tmp = (*l_eggs);
  if (!tmp->next && tmp->x == egg->x && tmp->y == egg->y)
    {
      printf("egg solo du coup remove\n");
      (*l_eggs) = NULL;
      return (0);
    }
  while (tmp)
    {
      if (tmp->next && tmp->next->x == egg->x && tmp->next->y == egg->y)
	{
	  save = tmp->next->next;
	  tmp->next = NULL;
	  tmp->next = save;
	  return (0);
	}
      tmp = tmp->next;
    }
  return (-1);
}
