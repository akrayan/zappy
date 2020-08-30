/*
** my_epure.c for my_epure.c in /home/thenascrazy/Minishell/PSU_2015_minishell1_list
**
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
**
** Started on  Tue Mar 29 17:51:07 2016 Afou Nacerdine
** Last update Sat Jun 17 00:58:31 2017 TheNasCrazy
*/

#include "../include/server.h"

char	*my_epure_str(char *str)
{
  int	i;
  int	j;

  i = -1;
  j = 0;
  while (str[++i] != '\0')
    {
      if (str[i] == '\t')
	str[i] = ' ';
    }
  i = -1;
  while (str[++i] == ' ');
  while (str[i] != '\0' && str[j] != '\0')
    {
      if (str[i] == ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
	i = i + 1;
      else
	{
	  str[j] = str[i];
	  j = j + 1;
	  i = i + 1;
	}
    }
  str[j] = '\0';
  return (str);
}
