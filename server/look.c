/*
** look.c for  in /home/laurent/rendu/PSU_2016_zappy
**
** Made by laurent
** Login   <laurent@epitech.net>
**
** Started on  Fri Jun 30 09:23:12 2017 laurent
** Last update Sun Jul  2 23:57:38 2017 laurent
*/

#include "../include/server.h"

void            look_suite(int i, int j, t_player **p)
{
  (*p)->resp = (char *)
    realloc((*p)->resp, sizeof(char) *
	    (strlen(((*p)->resp == NULL) ? " " : (*p)->resp) + 4));
  (*p)->resp = (j == (*p)->lvl && i == j * 2 + 1)
    ? strncat((*p)->resp, strdup(" ]\n"), 4) :
    strncat((*p)->resp, strdup(","), 2);
}

int               look_up(t_server *s, t_player *p)
{
  int   x;
  int   y;
  int   i;
  int   j;

  j = 0;
  y = p->y;
  p->resp = strdup("[");
  while (j <= p->lvl)
    {
      y = (y >= s->dim_y) ? y - s->dim_y : (y < 0) ? s->dim_y + y : y;
      x = p->x - j;
      i = 0;
      while (i <= j * 2 + 1)
	{
	  x = (x >= s->dim_x) ? x - s->dim_x : (x < 0) ? s->dim_x + x : x;
	  aff_tile(s, &p, x, y);
	  look_suite(i, j, &p);
	  x++;
	  i++;
	}
      y--;
      j++;
    }
  return (0);
}

int               look_down(t_server *s, t_player *p)
{
  int   x;
  int   y;
  int   i;
  int   j;

  j = 0;
  y = p->y;
  p->resp = strdup("[");
  while (j <= p->lvl)
    {
      y = (y >= s->dim_y) ? y - s->dim_y : (y < 0) ? s->dim_y + y : y;
      x = p->x + j;
      i = 0;
      while (i <= j * 2 + 1)
	{
	  x = (x >= s->dim_x) ? x - s->dim_x : (x < 0) ? s->dim_x + x : x;
	  aff_tile(s, &p, x, y);
	  look_suite(i, j, &p);
	  x--;
	  i++;
	}
      y++;
      j++;
    }
  return (0);
}

void               look_right(t_server *s, t_player *p)
{
  int   x;
  int   y;
  int   i;
  int   j;

  j = 0;
  x = p->x;
  p->resp = strdup("[");
  while (j <= p->lvl)
    {
      x = (x >= s->dim_x) ? x - s->dim_x : (x < 0) ? s->dim_x + x : x;
      y = p->y - j;
      i = 0;
      while (i <= j * 2 + 1)
	{
	  y = (y >= s->dim_y) ? y - s->dim_y : (y < 0) ? s->dim_y + y : y;
	  aff_tile(s, &p, x, y);
	  look_suite(i, j, &p);
	  y++;
	  i++;
	}
      x++;
      j++;

    }
}

int               look_left(t_server *s, t_player *p)
{
  int   x;
  int   y;
  int   i;
  int   j;

  j = 0;
  x = p->x;
  p->resp = strdup("[");
  while (j <= p->lvl)
    {
      x = (x >= s->dim_x) ? x - s->dim_x : (x < 0) ? s->dim_x + x : x;
      y = p->y + j;
      i = 0;
      while (i <= j * 2 + 1)
	{
	  y = (y >= s->dim_y) ? y - s->dim_y : (y < 0) ? s->dim_y + y : y;
	  aff_tile(s, &p, x, y);
	  look_suite(i, j, &p);
	  y--;
	  i++;
	}
      x--;
      j++;
    }
  return (0);
}
