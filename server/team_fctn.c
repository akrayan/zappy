/*
** init_fctn.c for  in /home/sabas/Documents/Systeme_unix/PSU_2016_zappy
**
** Made by SABAS
** Login   <nicoals.sabas@epitech.eu>
**
** Started on  Wed Jun 21 18:03:43 2017 SABAS
** Last update Sun Jul  2 23:41:40 2017 laurent
*/

#include "../include/server.h"

void		init_teams(t_team **teams, char **name_team, int nb_max)
{
  int		i;
  t_team	*elem;

  i = -1;
  if (name_team)
    while (name_team[++i])
      {
	if ((elem = malloc(sizeof(t_team))) == NULL)
	  return ;
	elem->name = name_team[i];
	elem->nb_max_player = nb_max;
	elem->nb_player = 0;
	elem->nb_eggs = 0;
	elem->next = (*teams);
	(*teams) = elem;
      }
}

void		check_graphic(t_server *s, t_player **p, char *msg)
{
  if (strcmp(msg, "GRAPHIC") == 0)
    {
      (*p)->fd_type = FD_graphique;
      welcome_gui(s, (*p), s->args->name_team);
      printf("Graphic connected\n");
    }
}

void		check_eggs(t_server *s, t_team **tmp, t_player **p)
{
  char		*send;
  t_eggs	*egg;

  (*tmp)->nb_player++;
  if ((*tmp)->nb_eggs > 0 &&
      (egg = search_eggs_hatching((*tmp), s->l_eggs)) != NULL)
    {
      (*p)->x = egg->x;
      (*p)->y = egg->y;
      asprintf(&send, "ebo %d\n", egg->id);
      rec_gui(&s->l_player, send);
      send_graphic(s);
      remove_egg(&s->l_eggs, egg);
    }
  dprintf((*p)->fd, "%d\n%d %d\n", ((*tmp)->nb_max_player - (*tmp)->nb_player)
	  , s->dim_x, s->dim_y);
  (*p)->fd_type = FD_client;
}

t_team		*join_team(t_team *l_team, t_player *p,
			   char *msg, t_server *s)
{
  t_team	*tmp;

  tmp = l_team;
  printf("enter name -> %s\n", msg);
  while (tmp)
    {
      if (strcmp(msg, tmp->name) == 0 &&
	  (tmp->nb_max_player - (tmp->nb_player + 1)) >= 0)
	{
	  check_eggs(s, &tmp, &p);
	  return (tmp);
	}
      else
	tmp = tmp->next;
    }
  dprintf(p->fd, "ko\n");
  return (tmp);
}

t_team		*search_team_by_name(t_team *l_team, char *name)
{
  t_team	*tmp;

  tmp = l_team;
  while (tmp)
    {
      if (strcmp(tmp->name, name) == 0)
	return (tmp);
      tmp = tmp->next;
    }
  return (tmp);
}
