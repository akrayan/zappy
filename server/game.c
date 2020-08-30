/*
** game.c for game.c in /home/rayan/System_Unix/Reseau/PSU_2016_zappy/server
**
** Made by Rayan
** Login   <raihane.akkache@epitech.eu>
**
** Started on  Wed Jun 14 16:57:43 2017 Rayan
** Last update Sun Jul  2 23:38:25 2017 laurent
*/

#include "../include/server.h"

void		gen_stones(t_server *server)
{
  server->rare_rsrc[0] = R_LINE;
  server->rare_rsrc[1] = R_DERA;
  server->rare_rsrc[2] = R_SIBU;
  server->rare_rsrc[3] = R_MEND;
  server->rare_rsrc[4] = R_PHIR;
  server->rare_rsrc[5] = R_THYS;
  server->rare_rsrc[6] = R_FOOD;
}

void		gen_map(t_server *server)
{
  int		i;
  int		j;

  gen_stones(server);
  server->ref_rsrc[0] = "food";
  server->ref_rsrc[1] = "linemate";
  server->ref_rsrc[2] = "deraumere";
  server->ref_rsrc[3] = "sibur";
  server->ref_rsrc[4] = "mendiane";
  server->ref_rsrc[5] = "phiras";
  server->ref_rsrc[6] = "thystame";
  if ((server->map = malloc(sizeof(char *) *
			    (server->dim_x * server->dim_y))) == NULL)
    exit(84);
  j = -1;
  while (++j < server->dim_x * server->dim_y)
    {
      server->map[j] = malloc(7);
      i = -1;
      while (++i < 7)
	server->map[j][i] = !(rand() %
			      (server->rare_rsrc[i])) ? rand() % 6 : 0;
    }
}

void		aff_map2(t_server *s, int *b, int x, int y)
{
  t_player	*tmp;

  tmp = s->l_player;
  while (tmp)
    {
      if (tmp->x == x && tmp->y == y && tmp->fd_type == FD_client)
	{
	  printf(" \033[31m%d\033[0m ", tmp->fd);
	  (*b) = 1;
	}
      tmp = tmp->next;
    }
  if ((*b) == 0)
    {
      printf(" 0 ");
      (*b) = 0;
    }
}

void		aff_map(t_server *s)
{
  int		x;
  int		y;
  int		b;

  y = -1;
  x = -1;
  while (++y < s->dim_y)
    {
      x = -1;
      while (++x < s->dim_x)
	{
	  b = 0;
	  aff_map2(s, &b, x, y);
	}
      printf("\n");
    }
}
