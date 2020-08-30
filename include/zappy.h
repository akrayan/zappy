/*
** zappy.h for zappy.h in /home/rayan/System_Unix/Reseau/PSU_2016_zappy/include
**
** Made by Rayan
** Login   <raihane.akkache@epitech.eu>
**
** Started on  Wed Jun 14 16:59:39 2017 Rayan
** Last update Wed Jun 21 11:22:15 2017 TheNasCrazy
*/

#ifndef ZAPPY_H_
# define ZAPPY_H_

# include <stdlib.h>
# include <stdio.h>
# include <time.h>

typedef struct	s_player
{
  int		inventory[7];
  int		x;
  int		y;
  int		lvl;
  char		dir;
}		player;

typedef struct	s_game
{
  //char		*map;
  char       	**map;
  int		size_x;
  int		size_y;
  char		*ref_rsrc[8];
}		game;

#endif
