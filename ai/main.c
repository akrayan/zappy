/*
** main.c for main.c in /home/rayan/System_Unix/Reseau/PSU_2016_zappy/client
**
** Made by Rayan
** Login   <raihane.akkache@epitech.eu>
**
** Started on  Wed Jun 14 17:24:35 2017 Rayan
** Last update Sun Jul  2 20:10:21 2017 Afou Nacerdine
*/

#include "../include/client.h"

int		count_str(char *str, char *cmp)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (str[i] != '\0')
    {
      if (my_strncmp(str + i, cmp, my_strlen(cmp) - 1) == 0)
	count = count + 1;
      i = i + 1;
    }
  return (count);
}

int			send_msg(char *msg, t_client *client)
{
  fd_set		rfds;
  char			*result;
  int			i;

  i = 0;
  client->s = msg;
  result = my_strdup("\0");
  while (my_strlen(result) == 0)
    {
      init_select(client->fd, &rfds);
      if (i == 0)
	dprintf(client->fd, "%s", msg);
      i = 1;
      result = read_isset(client->fd, result, &rfds, client);
    }
  free(result);
  return (0);
}

int		main_loop(t_client *client)
{
  client->player->pv = 10;
  client->player->lvl = 1;
  client->player->is_here = 0;
  client->player->step = -1;
  client->player->limit = (client->player->mapX > client->player->mapY) ?
  client->player->mapY : client->player->mapX;
  client->player->limit = client->player->limit + 1;
  client->player->turn = 0;
  client->player->lvlup = 0;
  client->player->leader = 0;
  init_elevation(client->player->elevation);
  while (42)
    {
      send_msg("Inventory\n", client);
      check_stone(client);
      check_incantation(client->player->lvl, client);
    }
  return (0);
}

int		main(int ac, char **av)
{
  t_client	client;

  if (ac != 5 && ac != 7)
    {
      display_help(av[0]);
      return (1);
    }
  client.player = malloc(sizeof(t_player));
  client.ip = NULL;
  if (check_arg(&client, av) == 1)
    return (0);
  if (init_server(&client) == -1)
    return (-1);
  client.player->wait_fork = 0;
  client.player->id = 0;
  init_welcome(&client);
  init_fork(&client);
  if (main_loop(&client) == -1)
    return (1);
  return (0);
}
