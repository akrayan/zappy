/*
** get_next_line.c for get_next_line in /home/atlani/Rendu/Tek2/PSU_réseau/PSU_2016_myftp
** 
** Made by Atlani
** Login   <mylan.atlani@epitech.eu>
** 
** Started on  Sun May 21 18:38:37 2017 Atlani
** Last update Sun May 21 18:38:37 2017 Atlani
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

char		*my_realloc(char *init, int size)
{
  char		*str;
  int		x;
  int		k;

  k = 0;
  str = init;
  x = 0;
  if ((init = malloc(size)) == NULL)
    return (0);
  while (str[x] != '\0')
    {
      init[k] = str[x];
      x = x + 1;
      k = k + 1;
    }
  return (init);
}

char		define_x(const int fd)
{
  static char	Buffer[READ_SIZE + 1] = "";
  static int	len1 = 0;
  char		x = 0;
  static char	*target = "";

  if (len1 == 0)
    {
      if ((len1 = read(fd, Buffer, READ_SIZE + 1)) == 0 || len1 == -1)
	return (0);
      target = Buffer;
    }
  x = *target;
  target = target + 1;
  len1 = len1 - 1;
  return (x);
}

char		*get_next_line(const int fd)
{
  char		x;
  char		*str;
  int		j;

  j = 0;
  if ((str = malloc(sizeof (char) * READ_SIZE + 1)) == NULL)
    return (0);
  x = define_x(fd);
  while (x != '\n' && x != '\0')
    {
      str[j] = x;
      x = define_x(fd);
      j = j + 1;
      str[j] = '\0';
      str = my_realloc(str, j + READ_SIZE + 1);
    }
  str[j] = 0;
  if (x == 0 && str[0] == 0)
    return (0);
  return (str);
}
