/*
** set.c for set.c in /home/afou_n/PSU_2016_zappy/ai
**
** Made by Afou Nacerdine
** Login   <nacerdine.afou@epitech.eu>
**
** Started on  Sun Jul  2 16:07:45 2017 Afou Nacerdine
** Last update Sun Jul  2 21:58:20 2017 Afou Nacerdine
*/

#include "../include/client.h"

int		set_lvl(t_client *client)
{
  char		*tmp;
  int		i;

  i = -1;
  while (++i < 6)
    {
      while (client->player->elevation[client->player->lvl - 1].stones[i].nb
	     > 0)
	{
	  tmp = my_strdup("Set ");
	  tmp = my_re(tmp,
	  client->player->elevation[client->player->lvl - 1].stones[i].type);
	  tmp = my_re(tmp, "\n");
	  send_msg(tmp, client);
	  client->player->elevation[client->player->lvl - 1].stones[i].nb -= 1;
	}
    }
  send_msg("Incantation\n", client);
  return (0);
}
