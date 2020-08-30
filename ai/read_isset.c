/*
** get_msg.c for get_msg.c in /home/thenascrazy/tek2/Systeme_Unix/projet/PSU_2016_zappy/ai
**
** Made by TheNasCrazy
** Login   <nacerdine.afou@epitech.eu>
**
** Started on  Tue Jun 27 15:28:59 2017 TheNasCrazy
** Last update Sun Jul  2 20:28:01 2017 Afou Nacerdine
*/

#include "../include/client.h"

char		*my_re(char *result, char *buffer)
{
  char		*new;

  new = malloc(sizeof(char) * (my_strlen(result) + my_strlen(buffer) + 1));
  my_strcpy(new, result);
  my_strcat(new, buffer);
  free(result);
  return (new);
}

char		*read_isset(int fd, char *result, fd_set *rfds, t_client *client)
{
  char		**tab;
  char		buffer[4096];
  int		ret;

  if (FD_ISSET(fd, rfds))
    {
      while (count_str(result, "\n") == 0)
	{
	  if ((ret = read(fd, buffer, 4096)) <= 0)
	    exit(1);
	  buffer[ret] = '\0';
	  result = my_re(result, buffer);
	}
      if (my_strlen(result) != 0)
	{
	  ret = -1;
	  tab = my_str_to_wordtab(result, '\n');
	  while (tab[++ret] != NULL)
	    check_cmd(client, tab[ret]);
	}
    }
  return (result);
}
