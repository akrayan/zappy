/*
** algo_ai.c for algo_ai.c in /home/thenascrazy/tek2/Systeme_Unix/projet/PSU_2016_zappy
**
** Made by TheNasCrazy
** Login   <nacerdine.afou@epitech.eu>
**
** Started on  Tue Jun 27 15:37:40 2017 TheNasCrazy
** Last update Sun Jul  2 17:36:33 2017 Afou Nacerdine
*/

#include "../include/client.h"

int		get_pv(char *s)
{
  int		i;
  int		j;
  int		pv;
  char		*tmp;

  i = -1;
  tmp = malloc(sizeof(char) * (my_strlen(s) + 1));
  while (s[++i] != '\0' && s[i] != ',');
  j = i;
  while (s[--j] != '\0' && s[j] != ' ');
  my_strncpy(tmp, s + j, i - j);
  pv = atoi(tmp);
  return (pv);
}
