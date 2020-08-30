/*
** pos.c for  in /home/parallels/rendu/PSU_2016_zappy/server
**
** Made by Parallels
** Login   <laurent.monfourny@epitech.eu>
**
** Started on  Sat Jun 24 12:40:01 2017 Parallels
** Last update Mon Jul  3 21:17:03 2017 laurent
*/

#include "../include/server.h"

void		move_pos(t_server *server, t_player **p)
{
  (*p)->dir == 1 ? (*p)->y++ : (*p)->dir == 2 ? (*p)->x++ : (*p)->dir == 3 ?
  (*p)->y-- : (*p)->dir == 4 ? (*p)->x-- : 1;
  if ((*p)->x < 0)
    (*p)->x += server->dim_x;
  else if ((*p)->x > (server->dim_x - 1))
    ((*p)->x) -= (server->dim_x);
  if ((*p)->y < 0)
    ((*p)->y) += (server->dim_y);
  else if ((*p)->y > (server->dim_y - 1))
    (*p)->y -= (server->dim_y);
}

void		eject_player(t_server *server, t_player **tmp, char dir, int *i)
{
  dir == 1 ? (*tmp)->y++ : dir == 2 ? (*tmp)->x++ : dir == 3 ?
    (*tmp)->y-- : dir == 4 ? (*tmp)->x-- : 1;
    if ((*tmp)->x < 0)
    (*tmp)->x += server->dim_x;
  else if ((*tmp)->x > (server->dim_x - 1))
    ((*tmp)->x) -= (server->dim_x);
  if ((*tmp)->y < 0)
    ((*tmp)->y) += (server->dim_y);
  else if ((*tmp)->y > (server->dim_y - 1))
    (*tmp)->y -= (server->dim_y);
  (*i)++;
}
