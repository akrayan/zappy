/*
** get_team.c for  in /home/laurent/rendu/PSU_2016_zappy/server
**
** Made by laurent
** Login   <laurent@epitech.net>
**
** Started on  Sun Jul  2 16:00:31 2017 laurent
** Last update Sun Jul  2 16:00:51 2017 laurent
*/

#include "../include/server.h"

int     get_team(t_arg *args, char **av)
{
  int   i;

  i = 0;
  while (av[i] && av[i][0] != '-')
    i++;
  if ((args->name_team = malloc(sizeof(char *) * (i + 1))) == NULL)
    exit (84);
  i = 0;
  while (av[i] && av[i][0] != '-')
    {
      if ((args->name_team[i] = strdup(av[i])) == NULL)
	exit (84);
      i++;
    }
  args->name_team[i] = NULL;
  return (i);
}
