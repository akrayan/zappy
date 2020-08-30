/*
** take.c for take.c in /home/afou_n/PSU_2016_zappy/ai
**
** Made by Afou Nacerdine
** Login   <nacerdine.afou@epitech.eu>
**
** Started on  Sun Jul  2 16:05:38 2017 Afou Nacerdine
** Last update Sun Jul  2 16:18:35 2017 Afou Nacerdine
*/

#include "../include/client.h"

int		take_lvl(t_client *client, char **tab)
{
  char		*tmp;

  tmp = my_strdup("Take ");
  tmp = my_re(tmp, tab[my_tablen(tab) - 1]);
  tmp = my_re(tmp, "\n");
  send_msg(tmp, client);
  return (0);
}
