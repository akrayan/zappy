/*
** get.c for get.c in /home/thenascrazy/tek2/Systeme_Unix/projet/PSU_2016_zappy
**
** Made by TheNasCrazy
** Login   <nacerdine.afou@epitech.eu>
**
** Started on  Fri Jun 30 10:39:42 2017 TheNasCrazy
** Last update Fri Jun 30 14:08:34 2017 TheNasCrazy
*/

#include "../include/client.h"

int	get_inventory(t_inventory *inventory, char *cmd)
{
  char		**tab;
  char		**tab_tmp;
  char		*tmp;
  int		i;

  i = -1;
  tmp = my_strdup(cmd);
  tmp[0] = ' ';
  tmp[my_strlen(tmp) - 1] = ' ';
  my_epure_str(tmp);
  tab = my_str_to_wordtab(tmp, ',');
  while (tab[++i] != NULL)
    {
      my_epure_str(tab[i]);
      tab_tmp = my_str_to_wordtab(tab[i], ' ');
      inventory[i].type = my_strdup(tab_tmp[0]);
      inventory[i].nb = atoi(tab_tmp[1]);
      free_tab(tab_tmp);
    }
  free_tab(tab);
  free(tmp);
  return (0);
}

char	**get_look(char **look, char *cmd)
{
  char	*tmp;
  int	i;

  tmp = my_strdup(cmd);
  tmp[0] = ' ';
  tmp[my_strlen(tmp) - 1] = ' ';
  my_epure_str(tmp);
  look = my_str_to_wordtab(tmp, ',');
  i = -1;
  while (look[++i] != NULL)
    my_epure_str(look[i]);
  free(tmp);
  return (look);
}
