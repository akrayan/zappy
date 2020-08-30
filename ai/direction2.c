/*
** direction2.c for direction2.c in /home/afou_n/PSU_2016_zappy/ai
**
** Made by Afou Nacerdine
** Login   <nacerdine.afou@epitech.eu>
**
** Started on  Sun Jul  2 16:22:11 2017 Afou Nacerdine
** Last update Sun Jul  2 18:38:02 2017 Afou Nacerdine
*/

#include "../include/client.h"

int		dir_5(t_client *client)
{
  send_msg("Left\n", client);
  send_msg("Left\n", client);
  return (0);
}

int		dir_6(t_client *client)
{
  send_msg("Right\n", client);
  return (0);
}

int		dir_7(t_client *client)
{
  send_msg("Right\n", client);
  return (0);
}

int		dir_8(t_client *client)
{
  send_msg("Forward\n", client);
  return (0);
}
