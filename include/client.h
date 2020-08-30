/*
** client.h for client.h in /home/thenascrazy/tek2/Systeme_Unix/projet/PSU_2016_zappy/ai
**
** Made by TheNasCrazy
** Login   <nacerdine.afou@epitech.eu>
**
** Started on  Wed Jun 21 11:22:26 2017 TheNasCrazy
** Last update Sun Jul  2 20:09:19 2017 Afou Nacerdine
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include <sys/select.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <string.h>
# include "my.h"

typedef struct		s_inventory
{
  char			*type;
  int			nb;
}			t_inventory;

typedef struct		s_elevation
{
  t_inventory		*stones;
  int			nb_players;
}			t_elevation;

typedef struct		s_player
{
  char			*command;
  int			mapX;
  int			mapY;
  int			places;
  int			lvl;
  int			pv;
  t_inventory		inventory[7];
  int			step;
  char			**look;
  int			limit;
  int			turn;
  t_elevation		elevation[7];
  int			wait_fork;
  int			lvlup;
  int			is_here;
  int			id;
  int			leader;
}			t_player;

typedef struct		s_client
{
  struct protoent	*pe;
  struct sockaddr_in	s_in;
  int			fd;
  int			port;
  char			*ip;
  char			*name;
  char			*s;
  t_player		*player;
}			t_client;

# define INIT_STONES {{{"linemate", 1}, {"deraumere", 0}, {"sibur", 0}, \
							    {"mendiane", 0}, {"phiras", 0}, {"thystame", 0}}, \
      {{"linemate", 1}, {"deraumere", 1}, {"sibur", 1}, \
					    {"mendiane", 0}, {"phiras", 0}, {"thystame", 0}}, \
	{{"linemate", 2}, {"deraumere", 0}, {"sibur", 1}, \
					      {"mendiane", 0}, {"phiras", 2}, {"thystame", 0}}, \
	  {{"linemate", 1}, {"deraumere", 1}, {"sibur", 2}, \
						{"mendiane", 0}, {"phiras", 1}, {"thystame", 0}}, \
	    {{"linemate", 1}, {"deraumere", 2}, {"sibur", 1}, \
						  {"mendiane", 3}, {"phiras", 0}, {"thystame", 0}}, \
	      {{"linemate", 1}, {"deraumere", 2}, {"sibur", 3}, \
						    {"mendiane", 0}, {"phiras", 1}, {"thystame", 0}}, \
		{{"linemate", 2}, {"deraumere", 2}, {"sibur", 2}, \
						      {"mendiane", 2}, {"phiras", 2}, {"thystame", 1}}};

int		get_pv(char *s);
int		algo_ai(t_client *client, t_player *player);
void		display_help(char *str);
int		check_arg(t_client *client, char **av);
int		get_inventory(t_inventory *inventory, char *cmd);
char		**get_look(char **look, char *cmd);
int		init_server(t_client *client);
int		init_welcome(t_client *client);
int		init_select(int fd, fd_set *rfds);
int		init_fork(t_client *client);
int		init_elevation(t_elevation *elevation);
int		lvl_1(t_client *client);
int		lvl_2(t_client *client);
int		lvl_3(t_client *client);
int		lvl_4(t_client *client);
int		lvl_5(t_client *client);
char		*my_epure_str(char *str);
void		free_tab(char **tab);
int		count_tab(char *str, char c);
char		**my_str_to_wordtab(char *str, char c);
int		count_tab2(char *str, char c);
char		**my_str_to_wordtab2(char *str, char c);
char		*my_re(char *result, char *buffer);
char		*read_isset(int fd, char *result, fd_set *rfds, t_client *client);
int		id_cmd(char *cmp);
int		check_cmd(t_client *client, char *cmd);
int		cmd_look(t_client *client, char *cmd);
int		cmd_inventory(t_client *client, char *cmd);
int		cmd_elevation(t_client *client, char *cmd);
int		cmd_broadcast(t_client *client, char *cmd);
int		cmd_unknown(t_client *client, char *cmd);
int		count_str(char *str, char *cmp);
int		send_msg(char *msg, t_client *client);
int		main_loop(t_client *client);
int		main(int ac, char **av);
char		*maj(char *chaine);
char		*crypt(char *str, char *key);
int		dir_0(t_client *client);
int		dir_1(t_client *client);
int		dir_2(t_client *client);
int		dir_3(t_client *client);
int		dir_4(t_client *client);
int		lvl_6(t_client *client);
int		lvl_7(t_client *client);
int		lvl_8(t_client *client);
int		take_lvl(t_client *client, char **tab);
int		set_lvl(t_client *client);
int		dir_5(t_client *client);
int		dir_6(t_client *client);
int		dir_7(t_client *client);
int		dir_8(t_client *client);
int		check_algo_move(t_client *client);
int		check_direction(int direction, t_client *client);
int		check_incantation(int lvl, t_client *client);
int		check_stone(t_client *client);
int		check_live(t_client *client, int maxpv);
int		need_stone(t_inventory *diff);
int		create_diff(t_client *client, t_inventory *diff);
int		loop_stones(t_client *client, t_inventory *diff);
int		cmd_welcome(t_client *client, char *cmd);

#endif /* !CLIENT_H_ */
