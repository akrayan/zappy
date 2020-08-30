/*
** cmd.c for cmd.c in /home/thenascrazy/tek2/Systeme_Unix/projet/PSU_2016_zappy
**
** Made by TheNasCrazy
** Login   <nacerdine.afou@epitech.eu>
**
** Started on  Fri Jun 30 00:01:19 2017 TheNasCrazy
** Last update Tue Jul  4 02:16:07 2017 Afou Nacerdine
*/

#include "../include/client.h"

int		cmd_look(t_client *client, char *cmd)
{
  client->player->look = get_look(client->player->look, cmd);
  return (0);
}

int		cmd_inventory(t_client *client, char *cmd)
{
  cmd = cmd;
  get_inventory(client->player->inventory, cmd);
  client->player->pv = client->player->inventory[0].nb;
  return (0);
}

int		cmd_elevation(t_client *client, char *cmd)
{
  cmd = cmd;
  client->player->lvl = client->player->lvl + 1;
  client->player->step = -1;
  client->player->is_here = 0;
  my_printf("je lvl up\n %d", client->player->lvl);
  return (0);
}

int		cmd_broadcast(t_client *client, char *cmd)
{
  client = client;
  cmd = cmd;
  return (0);
}

int		cmd_unknown(t_client *client, char *cmd)
{
  client = client;
  cmd = cmd;
  return (0);
}
