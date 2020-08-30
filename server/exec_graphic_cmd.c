/*
** graphic_cmd.c for  in /home/sabas/Documents/Systeme_unix/PSU_2016_zappy
**
** Made by SABAS
** Login   <nicoals.sabas@epitech.eu>
**
** Started on  Sun Jul  2 19:36:57 2017 SABAS
** Last update Sun Jul  2 23:49:34 2017 laurent
*/

#include "../include/server.h"

int             id_cmd_graphic(char **arg)
{
  int           i;
  char          *tab[9];

  tab[0] = "msz";
  tab[1] = "bct";
  tab[2] = "tna";
  tab[3] = "ppo";
  tab[4] = "plv";
  tab[5] = "pin";
  tab[6] = "sgt";
  tab[7] = "sst";
  tab[8] = "mct";
  i = -1;
  while (++i < 9 && tab[i] && strcmp(tab[i], arg[0]) != 0);
  printf("%d       %s\n", i, arg[0]);
  return (i);
}

int             exec_cmd_graphic(char *cmd, t_server *serv, t_player *play)
{
  int           (*tab[10])(t_server *server,
			   t_player *player, char **arg);
  char          **arg;

  tab[0] = cmd_msz;
  tab[1] = cmd_bct;
  tab[2] = cmd_tna;
  tab[3] = cmd_ppo;
  tab[4] = cmd_plv;
  tab[5] = cmd_pin;
  tab[6] = cmd_sgt;
  tab[7] = cmd_sst;
  tab[8] = cmd_mct;
  tab[9] = cmd_unknow;
  arg = my_str_to_wordtab(cmd, ' ');
  (*tab[id_cmd_graphic(arg)])(serv, play, arg);
  return (0);
}

void            read_graphic(t_server *server, t_player *p)
{
  static char   buff[4096];
  int           i;

  i = 0;
  if (!server)
    return ;
  if ((i = read(p->fd, buff, 4096)) > 0)
    {
      buff[i - 1] = '\0';
      exec_cmd_graphic(buff, server, p);
      memset(buff, 0, 4096);
    }
  else
    quit_client(server, &p);
}
