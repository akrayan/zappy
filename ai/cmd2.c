/*
** cmd2.c for cmd2.c in /home/afou_n/PSU_2016_zappy/ai
**
** Made by Afou Nacerdine
** Login   <nacerdine.afou@epitech.eu>
**
** Started on  Sun Jul  2 17:23:06 2017 Afou Nacerdine
** Last update Tue Jul  4 02:16:28 2017 Afou Nacerdine
*/

#include "../include/client.h"

int		cmd_welcome(t_client *client, char *cmd)
{
  char		**tab;

  static int	i = 0;

  if (i == 0)
    {
      client->player->places = atoi(cmd);
      i = 1;
    }
  else if (i == 1)
    {
      tab = my_str_to_wordtab(cmd, ' ');
      client->player->mapX = atoi(tab[0]);
      client->player->mapY = atoi(tab[1]);
      free_tab(tab);
      i = 0;
    }
  client->player->wait_fork = 0;
  return (0);
}
