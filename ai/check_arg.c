/*
** check_arg.c for check_arg.c in /home/thenascrazy/tek2/Systeme_Unix/projet/PSU_2016_zappy/ai
**
** Made by TheNasCrazy
** Login   <nacerdine.afou@epitech.eu>
**
** Started on  Wed Jun 21 16:45:49 2017 TheNasCrazy
** Last update Wed Jun 21 16:46:17 2017 TheNasCrazy
*/

#include "../include/client.h"

void		display_help(char *str)
{
  printf("USAGE: %s -p port -n name -h machine\n", str);
  printf("\t\bport\t\bis the port number\n");
  printf("\t\bname\t\bis the name of the team\n");
  printf("\t\bmachine\t\bis the name of machine; localhost by default\n");
}

int		check_arg(t_client *client, char **av)
{
  int		i;

  i = 0;
  while (av[i] != NULL)
    {
      if (strcmp("-p", av[i]) == 0)
	client->port = atoi(av[i + 1]);
      else if (strcmp("-n", av[i]) == 0)
	client->name = strdup(av[i + 1]);
      else if (strcmp("-h", av[i]) == 0)
	client->ip = strdup(av[i + 1]);
      else if (strcmp("-help", av[i]) == 0)
	{
	  display_help(av[0]);
	  return (1);
	}
      i = i + 1;
    }
  if (client->ip == NULL)
    client->ip = strdup("127.0.0.1");
  return (0);
}
