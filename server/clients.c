/*
** clients.c for  in /home/laurent/rendu/PSU_2016_zappy/server
**
** Made by laurent
** Login   <laurent@epitech.net>
**
** Started on  Sun Jul  2 19:02:05 2017 laurent
** Last update Mon Jul  3 00:00:38 2017 laurent
*/

#include "../include/server.h"

void		quit_client(t_server *s, t_player **p)
{
  char		*send;

  close((*p)->fd);
  asprintf(&send, "pdi %d\n", (*p)->fd);
  rec_gui(&s->l_player, send);
  send_graphic(s);
  printf("%d disconnected\n", (*p)->fd);
  ((*p)->team == NULL) ? dprintf((*p)->fd, "team NULL")
    : (*p)->team->nb_player--;
  (*p)->fd_type = FD_free;
}

void            check_team(t_server *server, t_player **p, char *buff)
{
  char          *send;

  (*p)->team = join_team(server->l_team, (*p), buff, server);
  if ((*p)->team)
    {
      asprintf(&send, "pnw %d %d %d %d %d %s\n", (*p)->fd, (*p)->x, (*p)->y,
	       (*p)->dir, (*p)->lvl, (*p)->team->name);
      rec_gui(&server->l_player, send);
      send_graphic(server);
    }
}

void            read_client(t_server *server, t_player *p)
{
  char		buff[4096];
  int           i[2];

  if (!server)
    return ;
  if ((i[1] = read(p->fd, buff, 4096)) > 0)
    {
      buff[i[1] - 1] = '\0';
      printf("\n[Player->%d]: %s\n", p->fd, buff);
      check_graphic(server, &p, buff);
      if (p->team == NULL && p->fd_type != FD_graphique)
	check_team(server, &p, buff);
      else
	{
	  (queu_size(p) < 10) ? add_cmd(&p->l_cmd, buff) : 1;
	  printf("queu : %d | buff : %s\n", queu_size(p), p->l_cmd->cmd);
	}
      memset(buff, 0, 4096);
    }
  else
    quit_client(server, &p);
}
