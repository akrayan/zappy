/*
** my_str_to_wordtab.c for my_str_to_wordtab.c in /home/thenascrazy/tek2/Systeme_Unix/projet/PSU_2016_myftp/server_d
**
** Made by TheNasCrazy
** Login   <nacerdine.afou@epitech.eu>
**
** Started on  Fri Jun 16 01:33:37 2017 TheNasCrazy
** Last update Thu Jun 29 13:02:05 2017 TheNasCrazy
*/

#include "../include/client.h"

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i = i + 1;
    }
  free(tab);
}

int		count_tab(char *str, char c)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (str[i] != '\0')
    {
      while (str[i] != '\0' && str[i] != c)
	i = i + 1;
      count = count + 1;
      while (str[i] != '\0' && str[i] == c)
	i = i + 1;
    }
  return (count);
}

char		**my_str_to_wordtab(char *str, char c)
{
  char		**tab;
  int		i;
  int		j;
  int		k;

  i = 0;
  k = 0;
  tab = malloc(sizeof(char *) * (count_tab(str, c) + 1));
  while (str[i] != '\0')
    {
      j = i;
      while (str[i] != '\0' && str[i] != c)
	i = i + 1;
      tab[k] = malloc(sizeof(char) * (i -j + 1));
      tab[k] = my_strncpy(tab[k], str + j, i - j);
      k = k + 1;
      while (str[i] != '\0' && str[i] == c)
	i = i + 1;
    }
  tab[k] = NULL;
  return (tab);
}

int		count_tab2(char *str, char c)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (str[i] != '\0')
    {
      while (str[i] != '\0' && str[i] != c)
	i = i + 1;
      count = count + 1;
      while (str[i] != '\0' && str[i] == c)
	i = i + 1;
    }
  return (count);
}

char		**my_str_to_wordtab2(char *str, char c)
{
  char		**tab;
  int		i;
  int		j;
  int		k;

  i = 0;
  k = 0;
  tab = malloc(sizeof(char *) * (count_tab(str, c) + 1));
  while (str[i] != '\0')
    {
      j = i;
      while (str[i] != '\0' && str[i] != c)
	i = i + 1;
      tab[k] = malloc(sizeof(char) * (i -j + 1));
      tab[k] = my_strncpy(tab[k], str + j, i - j);
      k = k + 1;
      while (str[i] != '\0' && str[i] == c)
	i = i + 1;
    }
  tab[k] = NULL;
  return (tab);
}
