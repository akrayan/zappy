/*
** my_str_to_wordtab.c for  in /home/ruben/test
**
** Made by habib_r
** Login   <ruben@epitech.net>
**
** Started on  Mon Mar 28 20:01:59 2016 habib_r
** Last update Mon Jul  3 17:56:42 2017 SABAS
*/

#include "../include/server.h"

void	my_epur_str(char *str, char sep)
{
  int	i;
  int	j;

  i = -1;
  if (!str || str[0] == '\0')
    return ;
  while (str[++i] && str[i] == sep);
  i = i - 1;
  j = -1;
  while (str && str[++i])
    {
      str[++j] = str[i];
      if (str[i] == sep)
	{
	  while (str[i] == sep)
	    i = i + 1;
	  i = i - 1;
	}
    }
  if (str[j] == sep)
    str[j] = 0;
  else
    str[++j] = 0;
}

int	my_alloc_tab(char *str, char sep)
{
  int	i;
  int	count;

  i = -1;
  count = 0;
  while (str && str[++i])
    if (str[i] == sep)
      {
	str[i] = 0;
	count = count + 1;
      }
  return (count);
}

char	**my_str_to_wordtab(char *str, char sep)
{
  int	i;
  int	size;
  int	pos;
  char	**tab;

  i = -1;
  pos = 0;
  my_epur_str(str, sep);
  size = strlen(str);
  if ((tab = malloc(sizeof(char *) * (my_alloc_tab(str, sep) + 2))) == NULL)
    return (NULL);
  tab[pos] = str;
  while (++i < size)
    if (str[i] == 0)
      tab[++pos] = str + i + 1;
  tab[++pos] = NULL;
  return (tab);
}
