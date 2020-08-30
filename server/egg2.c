/*
** egg2.c for  in /home/sabas/Documents/Systeme_unix/PSU_2016_zappy
** 
** Made by SABAS
** Login   <nicoals.sabas@epitech.eu>
** 
** Started on  Sun Jul  2 18:08:54 2017 SABAS
** Last update Sun Jul  2 18:18:49 2017 SABAS
*/

#include "../include/server.h"

void		hatching2(t_eggs **eggs, double diff, t_server *server)
{
  char		*send;
  t_eggs	*tmp;

  tmp = *eggs;
  while (tmp)
    {
      if (tmp->time_hatching <= 0 && tmp->can_connect == 0)
	{
	  printf("Team %s can connect one more\n", tmp->team->name);
	  asprintf(&send, "eht %d\n", tmp->id);
	  rec_gui(&server->l_player, send);
	  send_graphic(server);
	  tmp->team->nb_max_player++;
	  tmp->can_connect = 1;
	}
      tmp = tmp->next;
      if (tmp)
	tmp->time_hatching -= diff;
    }
}
