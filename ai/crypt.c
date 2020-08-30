/*
** crypt.c for crypt in /home/rouman_r/rendu/test/102cipher
**
** Made by Roumanille
** Login   <rouman_r@epitech.eu>
**
** Started on  Wed Jun 28 16:50:10 2017 Roumanille
** Last update Tue Jul  4 02:17:30 2017 Afou Nacerdine
*/

#include "../include/client.h"

char *maj(char *chaine)
{
  int i;

  i = -1;
  while (chaine[++i] != '\0')
    {
      if (chaine[i] >= 'A' &&  chaine[i] <= 'Z')
	chaine[i] -= 'A' - 'a';
    }
  return (chaine);
}

char	*crypt(char *str, char *key)
{
  int	i;
  int	j;
  int	c_char;
  char	*msg;

  i = 0;
  j = 0;
  msg = malloc(sizeof(char) * (my_strlen(str) + 1));
  sscanf(str, "%[^\t\n]", msg);
  while (i < my_strlen(msg))
    {
      if (j >= my_strlen(key))
	j = 0;
      c_char = msg[i] ^ key[j];
      if (c_char < 32)
	c_char += 32;
      str[i] = c_char;
      j++;
      i++;
    }
  str[i] = '\0';
  free(msg);
  str = maj(str);
  return (str);
}
