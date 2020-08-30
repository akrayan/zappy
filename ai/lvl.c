/*
** lvl.c for lvl.c in /home/thenascrazy/tek2/Systeme_Unix/projet/PSU_2016_zappy
**
** Made by TheNasCrazy
** Login   <nacerdine.afou@epitech.eu>
**
** Started on  Fri Jun 30 11:00:42 2017 TheNasCrazy
** Last update Tue Jul  4 02:16:51 2017 Afou Nacerdine
*/

#include "../include/client.h"

int		lvl_1(t_client *client)
{
  char		**tab;

  tab = my_str_to_wordtab(client->player->look[0], ' ');
  if (my_tablen(tab) > 1)
    take_lvl(client, tab);
  else
    set_lvl(client);
  return (0);
}

int		lvl_2(t_client *client)
{
  char		*tmp;

  tmp = my_strdup("Broadcast   \0");
  tmp[my_strlen(tmp) - 2] = client->player->lvl + 48;
  tmp[my_strlen(tmp) - 1] = '-';
  tmp = my_re(tmp, "je peux lvl up\n");
  send_msg(tmp, client);
  client->player->leader = 1;
  while (client->player->is_here == 0 && client->player->leader == 1)
    {
      send_msg("Inventory\n", client);
      send_msg(tmp, client);
      if (client->player->pv < 4)
	check_live(client, 45);
    }
  free(tmp);
  if (client->player->leader == 1 && client->player->is_here == 1)
    {
      send_msg("Broadcast tu reste la\n", client);
      lvl_1(client);
    }
  return (0);
}

int		lvl_3(t_client *client)
{
  client = client;
  return (0);
}

int		lvl_4(t_client *client)
{
  client = client;
  return (0);
}

int		lvl_5(t_client *client)
{
  client = client;
  return (0);
}
