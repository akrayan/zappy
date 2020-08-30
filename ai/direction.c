/*
** direction.c for direction.c in /home/afou_n/PSU_2016_zappy
**
** Made by Afou Nacerdine
** Login   <nacerdine.afou@epitech.eu>
**
** Started on  Sat Jul  1 20:01:58 2017 Afou Nacerdine
** Last update Sun Jul  2 18:37:16 2017 Afou Nacerdine
*/

#include "../include/client.h"

int		dir_0(t_client *client)
{
  send_msg("Broadcast je suis la\n", client);
  return (0);
}

int		dir_1(t_client *client)
{
  send_msg("Forward\n", client);
  return (0);
}

int		dir_2(t_client *client)
{
  send_msg("Forward\n", client);
  return (0);
}

int		dir_3(t_client *client)
{
  send_msg("Left\n", client);
  return (0);
}

int		dir_4(t_client *client)
{
  send_msg("Left\n", client);
  return (0);
}
