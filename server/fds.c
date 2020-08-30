/*
** fds.c for  in /home/laurent/rendu/PSU_2016_myirc/my_server
**
** Made by laurent
** Login   <laurent@epitech.net>
**
** Started on  Sun May 28 12:46:52 2017 laurent
** Last update Sun Jul  2 19:02:39 2017 laurent
*/

#include "../include/server.h"

void		init_lot_fd(t_server *server, fd_set *readfds)
{
  t_player	*p;

  p = server->l_player;
  FD_SET(server->fd, readfds);
  while (p != NULL)
    {
      if (p->fd_type != FD_free)
	FD_SET(p->fd, readfds);
      p = p->next;
    }
}

int				get_max_fd(t_server *server)
{
  t_player			*p;
  int				r;

  r = 0;
  p = server->l_player;
  while (p != NULL)
    {
      if (r < p->fd && p->fd != FD_free)
	r = p->fd;
      p = p->next;
    }
  if (r < server->fd)
    r = server->fd;
  return (r + 1);
}

int		add_cmd(t_cmd **cmd, char *str)
{
  t_cmd		*tmp;
  t_cmd		*new;

  if ((new = malloc(sizeof(t_cmd))) == NULL)
    return (-1);
  new->cmd = strdup(str);
  new->next = NULL;
  if (*cmd == NULL)
    {
      *cmd = new;
      return (1);
    }
  tmp = *cmd;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
  return (0);
}

int		queu_size(t_player *player)
{
  int		i;
  t_cmd		*tmp;

  i = 0;
  tmp = player->l_cmd;
  while (tmp)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}
