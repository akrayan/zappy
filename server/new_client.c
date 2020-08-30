/*
** new_client.c for  in /home/laurent/rendu/PSU_2016_zappy/server
**
** Made by laurent
** Login   <laurent@epitech.net>
**
** Started on  Sun Jul  2 16:07:20 2017 laurent
** Last update Mon Jul  3 00:00:18 2017 laurent
*/

#include "../include/server.h"

void                    init_client(t_player **new, t_arg *args)
{
  (*new)->fd_type = FD_client;
  (*new)->lvl = 1;
  (*new)->dir = rand() % 4 + 1;
  (*new)->y = rand() % args->height;
  (*new)->team = NULL;
  (*new)->msg = NULL;
  (*new)->if_fork = 0;
  (*new)->if_inc = 0;
  (*new)->l_cmd = NULL;
  (*new)->if_br = 0;
  (*new)->inventory[FOOD] = PLAYER_FOOD;
  (*new)->inventory[LINEMATE] = PLAYER_LINEMATE;
  (*new)->inventory[DERAUMERE] = PLAYER_DERAUMERE;
  (*new)->inventory[SIBUR] = PLAYER_SIBUR;
  (*new)->inventory[MENDIANE] = PLAYER_MENDIANE;
  (*new)->inventory[PHIRAS] = PLAYER_PHIRAS;
  (*new)->inventory[THYSTAME] = PLAYER_THYSTAME;
  (*new)->inventory[7] = 0;
  (*new)->time_life = (126.f / args->freq) * 1000000;
  (*new)->time_action = (double)-1;
  (*new)->next = NULL;
  (*new)->x = rand() % args->width;
}

void                    new_client(t_server *server)
{
  struct sockaddr_in    sin;
  socklen_t             len;
  t_player              *p;
  t_player              *new;

  len = sizeof(sin);
  if ((new = malloc(sizeof(t_player))) == NULL)
    exit(84);
  if ((new->fd = accept(server->fd,
			(struct sockaddr *)&sin, &len)) == -1)
    exit(84);
  init_client(&new, server->args);
  printf("init x : %d y: %d dir : %d\n", new->x, new->y, new->dir);
  printf("%d connected\n", new->fd);
  dprintf(new->fd, "WELCOME\n");
  p = NULL;
  (server->l_player == NULL) ? (server->l_player = new) :
    (p = server->l_player);
  while (p != NULL && p->next != NULL)
    p = p->next;
  (p != NULL) ? (p->next = new) : (p = NULL);
}
