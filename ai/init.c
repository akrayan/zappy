/*
** init.c for init.c in /home/thenascrazy/tek2/Systeme_Unix/projet/PSU_2016_zappy/ai
**
** Made by TheNasCrazy
** Login   <nacerdine.afou@epitech.eu>
**
** Started on  Wed Jun 21 16:48:54 2017 TheNasCrazy
** Last update Tue Jul  4 02:13:44 2017 Afou Nacerdine
*/

#include "../include/client.h"

int		init_server(t_client *client)
{
  client->pe = getprotobyname("TCP");
  client->fd = socket(AF_INET, SOCK_STREAM, client->pe->p_proto);
  if (!client->pe)
    return (-1);
  if (client->fd == -1)
    return (-1);
  client->s_in.sin_family = AF_INET;
  client->s_in.sin_port = htons(client->port);
  client->s_in.sin_addr.s_addr = inet_addr(client->ip);
  if (connect(client->fd,
	      (struct sockaddr *)&client->s_in, sizeof(client->s_in)) == -1)
    {
      printf("Impossible d'etablir une connexion avec le serveur\n");
      if (close(client->fd) == -1)
	return (-1);
      return (-1);
    }
  return (0);
}

int		init_welcome(t_client *client)
{
  char		*tmp;

  client->s = get_next_line(client->fd);
  free(client->s);
  tmp = my_strdup(client->name);
  tmp = my_re(tmp, "\n");
  while (client->player->wait_fork == 1)
    {
      send_msg(tmp, client);
      if (client->player->wait_fork == 0)
	return (0);
    }
  send_msg(tmp, client);
  free(tmp);
  return (0);
}

int		init_select(int fd, fd_set *rfds)
{
  struct timeval	t;

  t.tv_usec = 0;
  t.tv_sec = 0;
  FD_ZERO(rfds);
  FD_SET(fd, rfds);
  if (select(fd + 1, rfds, NULL, NULL, &t) == -1)
    return (-1);
  return (0);
}

int		init_fork(t_client *client)
{
  int		i;
  pid_t		pid;

  i = -1;
  while (++i < 7)
    {
      if (client->player->places == 0)
	{
	  send_msg("Fork\n", client);
	  client->player->wait_fork = 1;
	}
      if ((pid = fork()) == -1)
	return (-1);
      if (pid == 0)
	{
	  if (init_server(client) == -1)
	    return (-1);
	  client->player->id += 1;
	  init_welcome(client);
	  main_loop(client);
	}
      if (client->player->places > 0)
	client->player->places -= 1;
    }
  return (0);
}

int		init_elevation(t_elevation *elevation)
{
  static t_inventory	stones[7][6] = INIT_STONES;

  elevation[0].nb_players = 1;
  elevation[0].stones = stones[0];
  elevation[1].nb_players = 2;
  elevation[1].stones = stones[1];
  elevation[2].nb_players = 2;
  elevation[2].stones = stones[2];
  elevation[3].nb_players = 4;
  elevation[3].stones = stones[3];
  elevation[4].nb_players = 4;
  elevation[4].stones = stones[4];
  elevation[5].nb_players = 6;
  elevation[5].stones = stones[5];
  elevation[6].nb_players = 6;
  elevation[6].stones = stones[6];
  return (0);
}
