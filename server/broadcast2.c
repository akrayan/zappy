/*
** broadcast2.c for  in /home/laurent/rendu/PSU_2016_zappy
**
** Made by laurent
** Login   <laurent@epitech.net>
**
** Started on  Sun Jul  2 02:38:59 2017 laurent
** Last update Mon Jul  3 20:45:54 2017 laurent
*/

#include "../include/server.h"

void    send_message(t_server *server, t_player *player)
{
  t_player  *players;

  printf("send message actif\n");
  players = server->l_player;
  while (players)
    {
      if (players->fd != player->fd)
	dprintf(players->fd, "%s", players->msg);
      players = players->next;
    }
}

void            set_sig(double *d, double tmp_d, int *virtual, int v)
{
  (*d) = tmp_d;
  (*virtual) = v;
}

void            set_sig_pos(int sig, int *x, int *y, t_player *tgt)
{
  int           x_max;
  int           y_max;

  x_max = (*x);
  y_max = (*y);
  (*x) = tgt->x;
  (*y) = tgt->y;
  (sig == 2) ? (*y) -= y_max : sig == 3 ? (*x) -= x_max :
    sig == 4 ? (*y) += y_max : sig == 5 ? (*x) += x_max : 1;
}

void            get_distance(t_player *src, t_player *tgt, int *x, int *y)
{
  int           x_max;
  int           y_max;
  double        d;
  double        d_f;
  int           sig;

  x_max = (*x);
  y_max = (*y);
  sig = 1;
  d = abs(sqrt(pow(tgt->x - src->x, 2) + pow(tgt->y - tgt->y, 2)));
  d_f = abs(sqrt(pow(tgt->x - src->x, 2) + pow(tgt->y - y_max - tgt->y, 2)));
  if (d_f < d)
    set_sig(&d, d_f, &sig, 2);
  d_f = abs(sqrt(pow(tgt->x - x_max - src->x, 2) + pow(tgt->y - tgt->y, 2)));
  if (d_f < d)
    set_sig(&d, d_f, &sig, 3);
  d_f = abs(sqrt(pow(tgt->x - src->x, 2) + pow(tgt->y + y_max - tgt->y, 2)));
  if (d_f < d)
    set_sig(&d, d_f, &sig, 4);
  d_f = abs(sqrt(pow(tgt->x + x_max - src->x, 2) + pow(tgt->y - tgt->y, 2)));
  if (d_f < d)
    set_sig(&d, d_f, &sig, 5);
  set_sig_pos(sig, x, y, tgt);
}
