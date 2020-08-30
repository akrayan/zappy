/*
** stones.c for stones.c in /home/afou_n/PSU_2016_zappy/ai
**
** Made by Afou Nacerdine
** Login   <nacerdine.afou@epitech.eu>
**
** Started on  Sun Jul  2 17:22:01 2017 Afou Nacerdine
** Last update Sun Jul  2 17:39:06 2017 Afou Nacerdine
*/

#include "../include/client.h"

int		need_stone(t_inventory *diff)
{
  int		i;

  i = 0;
  while (i < 6)
    {
      if (diff[i].nb > 0)
	return (0);
      i = i + 1;
    }
  return (1);
}

int		create_diff(t_client *client, t_inventory *diff)
{
  int		i;
  int		a;
  int		b;

  i = -1;
  while (++i < 6)
    {
      diff[i].type = client->player->inventory[i + 1].type;
      a = client->player->elevation[client->player->lvl - 1].stones[i].nb;
      b = client->player->inventory[i + 1].nb;
      diff[i].nb = a - b;
    }
  return (0);
}

int		loop_stones(t_client *client, t_inventory *diff)
{
  char		**tab;
  char		*tmp;
  int		i;
  int		j;

  i = -1;
  tab = my_str_to_wordtab(client->player->look[0], ' ');
  while (tab[++i] != NULL)
    {
      j = -1;
      while (++j < 6)
	{
	  if (my_strcmp(tab[i], diff[j].type) == 0 && diff[j].nb > 0)
	    {
	      tmp = my_strdup("Take ");
	      tmp = my_re(tmp, tab[i]);
	      tmp = my_re(tmp, "\n");
	      send_msg(tmp, client);
	      free(tmp);
	      diff[j].nb = diff[j].nb - 1;
	    }
	}
    }
  free_tab(tab);
  return (0);
}
