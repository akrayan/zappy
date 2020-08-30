/*
** header.h for  in /home/laurent/rendu/PSU_2016_zappy/server
**
** Made by laurent
** Login   <laurent@epitech.net>
**
** Started on  Mon Jul  3 21:20:28 2017 laurent
** Last update Mon Jul  3 08:55:35 2017 Laurent MONFOURNY
*/

#ifndef SERVER_H_
# define SERVER_H_

# define FD_free                0
# define FD_client              1
# define FD_server              2
# define FD_graphique           3
# define FD_MAX                 42

# define R_LINE                 4
# define R_DERA                 4
# define R_SIBU                 4
# define R_MEND                 4
# define R_PHIR                 4
# define R_THYS                 4
# define R_FOOD                 4

# define PLAYER_FOOD            9
# define PLAYER_LINEMATE        1
# define PLAYER_DERAUMERE       0
# define PLAYER_SIBUR           0
# define PLAYER_MENDIANE        0
# define PLAYER_PHIRAS          0
# define PLAYER_THYSTAME        0

# define _GNU_SOURCE

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <time.h>
# include <signal.h>
# include <stdbool.h>
# include <math.h>

typedef enum            s_index_inv
  {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    END
  }                     t_index_inv;

typedef struct          s_team
{
  int                   nb_max_player;
  int                   nb_player;
  int                   nb_eggs;
  char                  *name;
  struct s_team         *next;
}                       t_team;

typedef struct          s_cmd
{
  char                  *cmd;
  struct s_cmd          *next;
}                       t_cmd;

typedef struct          s_arg
{
  int                   port;
  int                   width;
  int                   height;
  char                  **name_team;
  int                   nb_clients;
  int                   freq;
}                       t_arg;

typedef struct          s_eggs
{
  double                time_hatching;
  int                   x;
  int                   y;
  int                   id;
  int                   can_connect;
  t_team                *team;
  struct s_eggs         *next;
}                       t_eggs;

typedef struct          s_player
{
  int                   inventory[7];
  int                   x;
  int                   y;
  int                   lvl;
  int                   fd;
  int                   if_fork;
  int                   if_inc;
  int                   if_br;
  char                  *resp;
  char                  *msg;
  char                  fd_type;
  char                  dir;
  double                time_action;
  double                time_life;
  t_team                *team;
  t_cmd                 *l_cmd;
  struct s_player       *next;
}                       t_player;

typedef struct          s_server
{
  int                   fd;
  int                   dim_x;
  int                   dim_y;
  char                  *ref_rsrc[8];
  char                  rare_rsrc[7];
  char                  fd_type;
  char                  **map;
  t_eggs                *l_eggs;
  t_player              *l_player;
  t_team                *l_team;
  struct s_arg          *args;
}                       t_server;

/* In ./incantation.c */
int			check_nb_good_players(t_server *s, t_player *p);
void			regen_case(t_server *s, int x, int y);
void			send_incantation_to_gui(t_server *s, t_player *p,
				int go_on, t_player *tmp);
int			incantation2(t_server *s, t_player *p, t_player *tmp);
int			incantation(t_server *s, t_player *p);
/* In ./take_obj.c */
void			send_take_obj_gui(t_server *s, t_player *p, int y);
int			take_obj(t_server *server, t_player **p, char *obj);
/* In ./new_client.c */
void			init_client(t_player **new, t_arg *args);
void			new_client(t_server *server);
/* In ./look2.c */
int			aff_tile(t_server *s, t_player **p, int x, int y);
char			*aff_eggs_look(t_server *server, int x, int y, char *source);
void			aff_title_suite(t_player **p, char *object);
/* In ./exec_graphic_cmd.c */
int			id_cmd_graphic(char **arg);
int			exec_cmd_graphic(char *cmd, t_server *serv, t_player *play);
void			read_graphic(t_server *server, t_player *p);
/* In ./fds.c */
void			init_lot_fd(t_server *server, fd_set *readfds);
int			get_max_fd(t_server *server);
int			add_cmd(t_cmd **cmd, char *str);
int			queu_size(t_player *player);
/* In ./get_team.c */
int			get_team(t_arg *args, char **av);
/* In ./win_fctn.c */
void			check_win(t_server *server);
void			send_win_msg(t_server *server, t_team *team);
void			close_all(t_server **server);
/* In ./cmd2.c */
int			cmd_eject(t_server *server, t_player *player, char **arg);
int			cmd_look(t_server *s, t_player *p, char **arg);
int			cmd_inventory(t_server *server, t_player *player, char **arg);
int			cmd_broadcast(t_server *server, t_player *player, char **arg);
int			cmd_connect_nbr(t_server *s, t_player *p, char **arg);
/* In ./broadcast.c */
void			check_good_dir(int *dir, char tgt_dir);
int			get_dir(int xa, int ya, int xb, int yb);
int			search(t_server *s, t_player *src, t_player *tgt);
void			my_broadcast(t_server *s, t_player *p, char **arg);
/* In ./leave_obj.c */
void			send_leave_obj_gui(t_server *s, t_player *p, int y);
int			leave_obj(t_server *s, t_player **p, char *obj);
void			play_cmd(t_cmd **cmds, t_server *server, t_player *player);
/* In ./eggs_fctn.c */
int			create_eggs(t_eggs **l_eggs, t_team *team,
			    t_server *server, t_player *player);
int			hatching_eggs(t_eggs **l_eggs, double diff, t_server *server);
int			add_fork_player(t_player *player, t_team *teams);
t_eggs			*search_eggs_hatching(t_team *team, t_eggs *l_eggs);
int			remove_egg(t_eggs **l_eggs, t_eggs *egg);
/* In ./g_cmd1.c */
/* In ./look.c */
void			look_suite(int i, int j, t_player **p);
int			look_up(t_server *s, t_player *p);
int			look_down(t_server *s, t_player *p);
void			look_right(t_server *s, t_player *p);
int			look_left(t_server *s, t_player *p);
/* In ./time.c */
int			take_food(t_player *player, t_server *server);
void			check_time_action(t_server *server, t_player **p, double diff);
void			check_time_life(t_server *server, t_player **p);
void			check_time(struct timeval *begin, struct timeval *end,
				   t_server *server);
/* In ./g_cmd2.c */
int			cmd_plv(t_server *s, t_player *p, char **arg);
int			cmd_sgt(t_server *s, t_player *p, char **arg);
int			cmd_pin(t_server *s, t_player *p, char **arg);
int			cmd_sst(t_server *s, t_player *p, char **arg);
/* In ./moove.c */
int			cmd_forward(t_server *server, t_player *p, char **arg);
int			cmd_right(t_server *server, t_player *p, char **arg);
int			cmd_left(t_server *server, t_player *p, char **arg);
/* In ./g_cmd.c */
int			cmd_msz(t_server *s, t_player *p, char **arg);
int			cmd_mct(t_server *s, t_player *p, char **arg);
int			cmd_tna(t_server *s, t_player *p, char **arg);
int			cmd_ppo(t_server *s, t_player *p, char **arg);
int			cmd_bct(t_server *s, t_player *p, char **arg);
/* In ./my_str_to_wordtab.c */
void			my_epur_str(char *str, char sep);
int			my_alloc_tab(char *str, char sep);
char			**my_str_to_wordtab(char *str, char sep);
/* In ./clients.c */
void			quit_client(t_server *s, t_player **p);
void			check_team(t_server *server, t_player **p, char *buff);
void			read_client(t_server *server, t_player *p);
/* In ./egg2.c */
void			hatching2(t_eggs **eggs, double diff, t_server *server);
/* In ./game.c */
void			gen_stones(t_server *server);
void			gen_map(t_server *server);
void			aff_map2(t_server *s, int *b, int x, int y);
void			aff_map(t_server *s);
/* In ./begin_incantation.c */
void			send_b_incantation_to_gui(t_server *s, t_player *p);
void			begin_incantation2(t_server *s, t_player *p, int i);
int			begin_incantation(t_server *s, t_player *p);
/* In ./tab_cmd.c */
int			id_cmd(char **arg);
int			exec_cmd(char *cmd, t_server *serv, t_player *play);
/* In ./com_gui.c */
int			rec_gui(t_player **players, char *send);
void			send_graphic(t_server *server);
void			welcome_gui(t_server *s, t_player *p, char **teams);
/* In ./pos.c */
void			move_pos(t_server *server, t_player **p);
void			eject_player(t_server *server, t_player **tmp,
				     char dir, int *i);
/* In ./check_stones_on_case.c */
bool			check_stones_on_case(t_server *s, char *lvl, int x, int y);
/* In ./main.c */
void			call_clients(t_server *server, fd_set *readfds);
void			init_select(t_server *server);
void			init_server(t_server *server);
int			main(int ac, char **av);
/* In ./check_args.c */
void			init_args(t_arg *args);
int			check_team_name(char **team);
int			check_struct(t_arg *args);
int			check_args2(int opts, char **av, t_arg *args);
int			check_args(int ac, char **av, t_server *server);
/* In ./get_next_line.c */
char			*my_realloc(char *init, int size);
char			define_x(const int fd);
char			*get_next_line(const int fd);
/* In ./cmd1.c */
int			cmd_fork(t_server *server, t_player *player, char **arg);
int			cmd_take(t_server *server, t_player *player, char **arg);
int			cmd_set(t_server *server, t_player *player, char **arg);
int			cmd_incantation(t_server *server, t_player *player, char **arg);
int			cmd_unknow(t_server *server, t_player *player, char **arg);
/* In ./team_fctn.c */
void			init_teams(t_team **teams, char **name_team, int nb_max);
void			check_graphic(t_server *s, t_player **p, char *msg);
void			check_eggs(t_server *s, t_team **tmp,
				   t_player **p);
t_team			*join_team(t_team *l_team, t_player *p,
			   char *msg, t_server *s);
t_team			*search_team_by_name(t_team *l_team, char *name);
/* In ./broadcast2.c */
void			send_message(t_server *server, t_player *player);
void			set_sig(double *d, double tmp_d, int *virtual, int v);
void			set_sig_pos(int sig, int *x, int *y, t_player *tgt);
void			get_distance(t_player *src, t_player *tgt, int *x, int *y);

#endif /* ! SERVER_H_ */
