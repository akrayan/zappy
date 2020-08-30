/*
** g_cmd2.c for  in /home/sabas/Documents/Systeme_unix/PSU_2016_zappy
**
** Made by SABAS
** Login   <nicoals.sabas@epitech.eu>
**
** Started on  Sun Jul  2 21:24:18 2017 SABAS
** Last update Sun Jul  2 23:46:49 2017 laurent
*/

#include "../include/server.h"

int             cmd_plv(t_server *s, t_player *p, char **arg)
{
  char          *send;
  t_player      *tmp;

  if (!arg[1])
    return (-1);
  tmp = p;
  while (tmp)
    {
      if (tmp->fd == atoi(arg[1]))
	{
	  asprintf(&send, "plv %d %d\n", tmp->fd, tmp->lvl);
	  rec_gui(&s->l_player, send);
	  send_graphic(s);
	  free(send);
	  return (0);
	}
      tmp = tmp->next;
    }
  return (-1);
}

int             cmd_sgt(t_server *s, t_player *p, char **arg)
{
  char          *send;

  p = p;
  arg = arg;
  asprintf(&send, "sgt %d\n", s->args->freq);
  rec_gui(&s->l_player, send);
  send_graphic(s);
  free(send);
  return (0);
}

int             cmd_pin(t_server *s, t_player *p, char **arg)
{
  char          *send;
  t_player      *tmp;

  if (!arg[1])
    return (-1);
  tmp = p;
  while (tmp)
    {
      if (tmp->fd == atoi(arg[1]))
	{
	  asprintf(&send, "pin %d %d %d %d %d %d %d %d %d %d\n",
		   p->fd, p->x, p->y, p->inventory[0],
		   p->inventory[1], p->inventory[2], p->inventory[3],
		   p->inventory[4], p->inventory[5], p->inventory[6]);
	  rec_gui(&s->l_player, send);
	  send_graphic(s);
	  free(send);
	  return (0);
	}
      tmp = tmp->next;
    }
  return (-1);
}

int             cmd_sst(t_server *s, t_player *p, char **arg)
{
  char          *send;

  p = p;
  if (!arg[1])
    return (-1);
  s->args->freq = atoi(arg[1]);
  asprintf(&send, "sgt %d\n", s->args->freq);
  rec_gui(&s->l_player, send);
  send_graphic(s);
  free(send);
  return (0);
}
