/*
** tab_cmd.c for  in /home/laurent/rendu/PSU_2016_zappy
**
** Made by laurent
** Login   <laurent@epitech.net>
**
** Started on  Fri Jun 30 09:18:17 2017 laurent
** Last update Sun Jul  2 23:54:56 2017 laurent
*/

#include "../include/server.h"

int		id_cmd(char **arg)
{
  int		i;
  char		*tab[12];

  tab[0] = "Forward";
  tab[1] = "Right";
  tab[2] = "Left";
  tab[3] = "Look";
  tab[4] = "Inventory";
  tab[5] = "Broadcast";
  tab[6] = "Connect_nbr";
  tab[7] = "Fork";
  tab[8] = "Eject";
  tab[9] = "Take";
  tab[10] = "Set";
  tab[11] = "Incantation";
  i = -1;
  while (++i < 12 && tab[i] && strcmp(tab[i], arg[0]) != 0);
  printf("%d       %s\n", i, arg[0]);
  return (i);
}

int		exec_cmd(char *cmd, t_server *serv, t_player *play)
{
  int		(*tab[13])(t_server *server,
			   t_player *player, char **arg);
  char		**arg;

  if ((play->time_action > 0 && play->fd_type == FD_client))
    return (dprintf(play->fd, "ko\n"));
  tab[0] = cmd_forward;
  tab[1] = cmd_right;
  tab[2] = cmd_left;
  tab[3] = cmd_look;
  tab[4] = cmd_inventory;
  tab[5] = cmd_broadcast;
  tab[6] = cmd_connect_nbr;
  tab[7] = cmd_fork;
  tab[8] = cmd_eject;
  tab[9] = cmd_take;
  tab[10] = cmd_set;
  tab[11] = cmd_incantation;
  tab[12] = cmd_unknow;
  arg = my_str_to_wordtab(cmd, ' ');
  (*tab[id_cmd(arg)])(serv, play, arg);
  return (0);
}
