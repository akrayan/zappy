/*
** win_fctn.c for  in /home/sabas/Documents/Systeme_unix/PSU_2016_zappy
**
** Made by SABAS
** Login   <nicoals.sabas@epitech.eu>
**
** Started on  Sun Jul  2 05:14:58 2017 SABAS
** Last update Sun Jul  2 23:37:23 2017 laurent
*/

#include "../include/server.h"

void		check_win(t_server *server)
{
  int		taille;
  t_player	*l_player;
  t_team	*l_team;

  taille = 0;
  l_team = server->l_team;
  while (l_team)
    {
      l_player = server->l_player;
      taille = 0;
      while (l_player)
  	{
	  if (l_player->team)
	    (strcmp(l_player->team->name, l_team->name) == 0
	     && l_player->lvl == 8) ? taille++ : 1;
  	  l_player = l_player->next;
  	}
      if (taille >= 6)
	send_win_msg(server, l_team);
      l_team = l_team->next;
    }
}

void		send_win_msg(t_server *server, t_team *team)
{
  char		*send;
  t_player	*player;

  player = server->l_player;
  while (player)
    {
      if (strcmp(player->team->name, team->name) == 0)
	dprintf(player->fd, "You win !\n");
      else
	dprintf(player->fd, "You lose !\n");
      player = player->next;
    }
  asprintf(&send, "seg %s\n", team->name);
  rec_gui(&server->l_player, send);
  send_graphic(server);
  close_all(&server);
}

void		close_all(t_server **server)
{
  int		i;
  t_team	*team;
  t_player	*player;

  i = -1;
  team = (*server)->l_team;
  player = (*server)->l_player;
  printf("Close all begin !\n");
  while (player)
    {
      close(player->fd);
      player = player->next;
    }
  (*server)->l_player = NULL;
  while (++i < (*server)->dim_y)
    free((*server)->map[i]);
  while ((team = team->next))
    free(team->name);
  free((*server)->l_team);
  close((*server)->fd);
  (*server) = NULL;
  exit(0);
}
