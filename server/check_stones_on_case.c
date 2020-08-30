/*
** check_stones_on_case.c for  in /home/laurent/rendu/PSU_2016_zappy/server
**
** Made by laurent
** Login   <laurent@epitech.net>
**
** Started on  Sun Jul  2 19:05:35 2017 laurent
** Last update Mon Jul  3 00:29:56 2017 SABAS
*/

#include "../include/server.h"

bool    check_stones_on_case(t_server *s, char *lvl, int x, int y)
{
  if (s->map[y * s->dim_x +  x][1] == lvl[2]
            && s->map[y * s->dim_x + x][2] == lvl[3] &&
            s->map[y * s->dim_x  + x][3] == lvl[4] &&
            s->map[y *  s->dim_x  + x][4] == lvl[5] &&
            s->map[y *  s->dim_x  + x][5] == lvl[6]
      && s->map[y *  s->dim_x + x][6] == lvl[7])
    return (true);
  return (false);
}
