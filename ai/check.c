/*
** check.c for check.c in /home/afou_n/PSU_2016_zappy/ai
**
** Made by Afou Nacerdine
** Login   <nacerdine.afou@epitech.eu>
**
** Started on  Sun Jul  2 17:17:51 2017 Afou Nacerdine
** Last update Sun Jul  2 19:45:34 2017 Afou Nacerdine
*/

#include "../include/client.h"

int		check_algo_move(t_client *client)
{
  if (--client->player->limit > 0)
    send_msg("Forward\n", client);
  else
    {
      if (client->player->turn == 0)
	{
	  send_msg("Left\n", client);
	  send_msg("Forward\n", client);
	  send_msg("Left\n", client);
	  client->player->turn = 1;
	}
      else
	{
	  send_msg("Right\n", client);
	  send_msg("Forward\n", client);
	  send_msg("Right\n", client);
	  client->player->turn = 0;
	}
      client->player->limit = (client->player->mapX > client->player->mapY)
      ? client->player->mapY : client->player->mapX;
      client->player->limit = client->player->limit + 1;
    }
  return (0);
}

int		check_direction(int direction, t_client *client)
{
  int		(*tab[9])(t_client *);

  tab[0] = &dir_0;
  tab[1] = &dir_1;
  tab[2] = &dir_2;
  tab[3] = &dir_3;
  tab[4] = &dir_4;
  tab[5] = &dir_5;
  tab[6] = &dir_6;
  tab[7] = &dir_7;
  tab[8] = &dir_8;
  (*tab[direction])(client);
  return (0);
}

int		check_incantation(int lvl, t_client *client)
{
  int		(*tab[8])(t_client *);

  tab[0] = &lvl_1;
  tab[1] = &lvl_2;
  tab[2] = &lvl_3;
  tab[3] = &lvl_4;
  tab[4] = &lvl_5;
  tab[5] = &lvl_6;
  tab[6] = &lvl_7;
  tab[7] = &lvl_8;
  if (client->player->step == 2)
    {
      while (client->player->step == 2)
	{
	  send_msg("Inventory\n", client);
	  if (client->player->pv < 4)
	    check_live(client, 15);
	  send_msg("Look\n", client);
	  (*tab[lvl - 1])(client);
	}
    }
  return (0);
}

int		check_stone(t_client *client)
{
  t_inventory	diff[6];

  if (client->player->lvlup == 1)
    return (0);
  create_diff(client, diff);
  if (need_stone(diff) == 0)
    {
      while (need_stone(diff) == 0)
	{
	  send_msg("Inventory\n", client);
	  if (client->player->pv < 4)
	    check_live(client, 15);
	  send_msg("Look\n", client);
	  create_diff(client, diff);
	  loop_stones(client, diff);
	  check_algo_move(client);
	  client->player->step = 1;
	}
    }
  client->player->step = 2;
  return (0);
}

int		check_live(t_client *client, int maxpv)
{
  while (client->player->pv < maxpv)
    {
      send_msg("Inventory\n", client);
      send_msg("Look\n", client);
      if (count_str(client->player->look[0], "food") > 0)
	send_msg("Take food\n", client);
      else
	check_algo_move(client);
    }
  return (0);
}
