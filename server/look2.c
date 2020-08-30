/*
** look2.c for  in /home/laurent/rendu/PSU_2016_zappy
**
** Made by laurent
** Login   <laurent@epitech.net>
**
** Started on  Fri Jun 30 09:28:36 2017 laurent
** Last update Sun Jul  2 23:58:07 2017 laurent
*/

#include "../include/server.h"

int             aff_tile(t_server *s, t_player **p, int x, int y)
{
  int           i;
  int           j;
  t_player      *tmp;

  tmp = s->l_player;
  while (tmp != NULL)
    {
      if (tmp->x == x && tmp->y == y && tmp->fd_type == FD_client)
	{
	  (*p)->resp = (char *)
	    realloc((*p)->resp, sizeof(char) *
		    (strlen(((*p)->resp == NULL) ? " " : (*p)->resp) + 8));
	  (*p)->resp = strncat((*p)->resp, strdup(" player"), 8);
	}
      tmp = tmp->next;
    }
  (*p)->resp = aff_eggs_look(s, x, y, (*p)->resp);
  i = -1;
  while (++i < 7)
    {
      j = -1;
      while (++j < s->map[x + y * s->dim_x][i])
	aff_title_suite(p, s->ref_rsrc[i]);
    }
  return (0);
}

char		*aff_eggs_look(t_server *server, int x, int y, char *source)
{
  char		*send;
  char		*new_line;
  t_eggs	*tmp;

  tmp = server->l_eggs;
  send = source;
  while (tmp)
    {
      if (tmp->y == y && tmp->x  == x)
	{
	  asprintf(&new_line, " egg");
	  send = (char *)realloc(send, sizeof(char) *
				 (strlen((send == NULL) ? " " : send) + strlen(new_line) + 2));
	  send = strncat(send, new_line, strlen(send) + strlen(new_line));
	}
      tmp = tmp->next;
    }
  return (send);
}

void            aff_title_suite(t_player **p, char *object)
{
  (*p)->resp = (char *)realloc((*p)->resp, sizeof(char) *
			       (strlen(((*p)->resp == NULL)
				       ? " " : (*p)->resp) + strlen(object) + 8)) ;
  (*p)->resp = strncat((*p)->resp, strdup(" "), 2);
  (*p)->resp = strncat((*p)->resp, object, strlen(object) + 1);
}
