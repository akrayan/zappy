/*
** g_cmd.c for  in /home/sabas/Documents/Systeme_unix/PSU_2016_zappy
**
** Made by SABAS
** Login   <nicoals.sabas@epitech.eu>
**
** Started on  Sun Jul  2 21:02:00 2017 SABAS
** Last update Sun Jul  2 23:45:21 2017 laurent
*/

#include "../include/server.h"

int		cmd_msz(t_server *s, t_player *p, char **arg)
{
  char		*send;

  p = p;
  arg = arg;
  asprintf(&send, "msz %d %d\n", s->dim_x, s->dim_y);
  rec_gui(&s->l_player, send);
  send_graphic(s);
  return (0);
}

int		cmd_mct(t_server *s, t_player *p, char **arg)
{
  int		i;
  t_player	*tmp;

  tmp = p;
  p = p;
  arg = arg;
  while (tmp)
    {
      if (tmp->fd_type == FD_graphique)
	{
	  i = -1;
	  while (++i < s->dim_x * s->dim_y)
	    dprintf(tmp->fd, "bct %d %d %d %d %d %d %d %d %d\n",
		    i % s->dim_x, i / s->dim_x,
		    s->map[i][0], s->map[i][1], s->map[i][2],
		    s->map[i][3], s->map[i][4], s->map[i][5], s->map[i][6]);
	}
      tmp = tmp->next;
    }
  return (0);
}

int		cmd_tna(t_server *s, t_player *p, char **arg)
{
  t_player	*player;
  t_team	*tmp;

  tmp = s->l_team;
  arg = arg;
  while (tmp)
    {
      player = p;
      while (player)
	{
	  if (player->fd_type == FD_graphique)
	    dprintf(player->fd, "tna %s\n", tmp->name);
	  player = player->next;
	}
      tmp = tmp->next;
    }
  return (0);
}

int		cmd_ppo(t_server *s, t_player *p, char **arg)
{
  char		*send;
  t_player	*tmp;

  if (!arg[1])
    return (-1);
  tmp = p;
  while (tmp)
    {
      if (tmp->fd == atoi(arg[1]))
	{
	  asprintf(&send, "ppo %d %d %c\n", tmp->x, tmp->y, tmp->dir);
	  rec_gui(&s->l_player, send);
	  send_graphic(s);
	  free(send);
	  return (0);
	}
      tmp = tmp->next;
    }
  return (-1);
}

int		cmd_bct(t_server *s, t_player *p, char **arg)
{
  char		*send;

  p = p;
  if (!arg[1] || !arg[2])
    return (-1);
  asprintf(&send, "bct %d %d %d %d %d %d %d %d %d\n",
	   atoi(arg[1]), atoi(arg[2]),
	   s->map[atoi(arg[2]) * s->dim_x + atoi(arg[1])][0],
	   s->map[atoi(arg[2]) * s->dim_x + atoi(arg[1])][1],
	   s->map[atoi(arg[2]) * s->dim_x + atoi(arg[1])][2],
	   s->map[atoi(arg[2]) * s->dim_x + atoi(arg[1])][3],
	   s->map[atoi(arg[2]) * s->dim_x + atoi(arg[1])][4],
	   s->map[atoi(arg[2]) * s->dim_x + atoi(arg[1])][5],
	   s->map[atoi(arg[2]) * s->dim_x + atoi(arg[1])][6]);
  rec_gui(&s->l_player, send);
  send_graphic(s);
  return (0);
}
