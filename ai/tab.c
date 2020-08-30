/*
** tab.c for tab.c in /home/thenascrazy/tek2/Systeme_Unix/projet/PSU_2016_myftp
**
** Made by TheNasCrazy
** Login   <nacerdine.afou@epitech.eu>
**
** Started on  Fri Jun 23 10:02:46 2017 TheNasCrazy
** Last update Sun Jul  2 16:00:47 2017 Afou Nacerdine
*/

#include "../include/client.h"

int		id_cmd(char *cmp)
{
  int		i;
  char		*tab[5];

  tab[0] = "[ player";
  tab[1] = "[ food";
  tab[2] = "Elevation underway";
  tab[3] = "message ";
  tab[4] = NULL;
  i = 0;
  while (tab[i] != NULL && my_strncmp(tab[i],
	 cmp, my_strlen(tab[i]) - 1) != 0)
    i = i + 1;
  return (i);
}

int		check_cmd(t_client *client, char *cmd)
{
  int		(*tab[6])(t_client *, char *);
  int		id;

  tab[0] = &cmd_look;
  tab[1] = &cmd_inventory;
  tab[2] = &cmd_elevation;
  tab[3] = &cmd_broadcast;
  tab[4] = &cmd_unknown;
  tab[5] = &cmd_welcome;
  if (my_strncmp(client->name, client->s, my_strlen(client->name) - 1) == 0
      && my_strcmp(cmd, "ko") != 0)
    {
      id = 5;
    }
  else
    id = id_cmd(cmd);
  (*tab[id])(client, cmd);
  return (0);
}
