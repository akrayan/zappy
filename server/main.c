/*
** main.c for  in /home/laurent/rendu/PSU_2016_zappy
**
** Made by laurent
** Login   <laurent@epitech.net>
**
** Started on  Wed Jun 28 12:24:20 2017 laurent
** Last update Sun Jul  2 23:40:26 2017 laurent
*/

#include "../include/server.h"

int			server_fd;

void		call_clients(t_server *server, fd_set *readfds)
{
  t_player	*p;

  p = server->l_player;
  if (FD_ISSET(server->fd, readfds) && server->fd_type == FD_server)
    new_client(server);
  while (p)
    {
      if (FD_ISSET(p->fd, readfds))
	{
	  if (p->fd_type == FD_client)
	    {
	      printf("\n[Player -> %d]x : %d y: %d dir : %d lvl: %d\n",
		     p->fd, p->x, p->y, p->dir, p->lvl);
	      read_client(server, p);
	      aff_map(server);
	    }
	  else if (p->fd_type == FD_graphique)
	    read_graphic(server, p);
	}
      play_cmd(&p->l_cmd, server, p);
      p = p->next;
    }
}

void			init_select(t_server *server)
{
  fd_set		readfds;
  struct timeval	tv;
  struct timeval	begin, end;
  int			ret;

  gettimeofday(&end, NULL);
  while (42)
    {
      check_time(&begin, &end, server);
      tv.tv_sec = 0;
      tv.tv_usec = (1 / server->args->freq) * 1000000;
      FD_ZERO(&readfds);
      init_lot_fd(server, &readfds);
      ret = select(get_max_fd(server), &readfds, NULL, NULL, &tv);
      if (ret == -1)
      	{
      	  printf("Error on select\n");
	  shutdown(server->fd, SHUT_RDWR);
      	  exit(84);
      	}
      call_clients(server, &readfds);
      check_win(server);
    }
}

void			init_server(t_server *server)
{
  struct protoent	*pe;
  struct sockaddr_in	sin;

  pe = getprotobyname("TCP");
  server->fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(server->args->port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if ((bind(server->fd, (const struct sockaddr *)&sin, sizeof(sin))) == -1)
    exit(printf("[ERROR] : bind : Permission denied\n"));
  if (listen(server->fd, FD_MAX) == -1)
    exit(printf("[ERROR] : accept : Permission denied\n"));
  server_fd = server->fd;
  server->fd_type = FD_server;
  server->l_player = NULL;
  server->l_team = NULL;
  server->l_eggs = NULL;
  server->dim_x = server->args->width;
  server->dim_y = server->args->height;
  init_teams(&server->l_team, server->args->name_team,
	     server->args->nb_clients);
  gen_map(server);
  init_select(server);
}

int		main(int ac, char **av)
{
  t_server	server;

  srand(time(NULL));
  if ((server.args = malloc(sizeof(t_arg))) == NULL)
    return (84);
  check_args(ac, av, &server);
  init_server(&server);
  return (0);
}
