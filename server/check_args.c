/*
** check_args.c for  in /home/laurent/rendu/PSU_2016_zappy/server
**
** Made by laurent
** Login   <laurent@epitech.net>
**
** Started on  Tue Jun 20 18:47:38 2017 laurent
** Last update Sun Jul  2 23:30:50 2017 laurent
*/

#include "../include/server.h"

void	init_args(t_arg *args)
{
  args->nb_clients = 3;
  args->freq = 100;
  args->port = 4242;
  args->name_team = NULL;
  args->width = 10;
  args->height = 10;
}

int	check_team_name(char **team)
{
  int	i;
  int	 y;

  i = -1;
  y = 0;
  while (team[++i])
    if (strcmp(team[i], "GRAPHIC") == 0)
      {
 	printf("\nGRAPHIC can't be the name of the team\n\n");
	return (1);
      }
  i = -1;
  while (team[++i])
    {
      y = -1;
      while (team[++y] && y != i)
	if (strcmp(team[y], team[i])== 0)
	  {
	    printf("\nThere is team duplication\n\n");
	    return (1);
	  }
    }
  return (0);
}

int	check_struct(t_arg *args)
{
  if (check_team_name(args->name_team) == 1);
  else if (args->port < 1023 || args->port > 655355)
    args->port = 4242;
  else if (args->width < 10 || args->width > 30)
    printf("\n-x option only accepts integer values between 10 and 30\n\n");
  else if (args->height < 10 || args->height > 30)
    printf("\n-y option only accepts integer values between 10 and 30\n\n");
  else if (args->freq < 2 || args->freq > 10000)
    printf("\n-f option only accepts integer values between 2 and 10000\n\n");
  else
    return (1);
  printf("USAGE: ./zappy_server -p port -x width -y ");
  printf("height -n name1 name2 ...");
  printf("-c clientsNb -f freq\n\n");
  printf("\tport      is the port number\n");
  printf("\twidth     is the width of the world\n");
  printf("\theight    is the height of the world\n");
  printf("\tnameX     is the name of the team X\n");
  printf("\tclientsNb is the number of authorized clients per team\n");
  printf("\tfreq      is the reciprocal of time unit ");
  printf("for execution of actions\n\n");
  return (0);
}

int	check_args2(int opts, char **av, t_arg *args)
{
  if (opts == 'n' && av[optind])
    optind += get_team(args, av + optind);
  if (opts == 'x' && av[optind])
    if ((args->width = atoi(av[optind])) == -1)
      return (-1);
  if (opts == 'y' && av[optind])
    if ((args->height = atoi(av[optind])) == -1)
      return (-1);
  if (opts != 'y' && opts != 'x' && opts != 'n' &&
      opts != 'f' && opts != 'c' && opts != 'p')
    exit(check_struct(args));
  return (0);
}

int	check_args(int ac, char **av, t_server *server)
{
  int	opts;

  init_args(server->args);
  while ((opts = getopt(ac, av, "pxyncf")) != -1)
    {
      if (opts == 'p' && av[optind])
	{
	  if ((server->args->port = atoi(av[optind])) == -1)
	    return (-1);
	}
      if (opts == 'c' && av[optind])
	{
	  if ((server->args->nb_clients = atoi(av[optind])) == -1)
	    return (-1);
	}
      if (opts == 'f' && av[optind])
	{
	  if ((server->args->freq = atoi(av[optind])) == -1)
	    return (-1);
	}
      if (check_args2(opts, av, server->args) == -1)
	return (-1);
    }
  (check_struct(server->args) == 0) ? exit(1) : 1;
  return (0);
}
