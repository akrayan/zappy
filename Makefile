##
## Makefile for Makefile in /home/rayan/System_Unix/Reseau/PSU_2016_zappy
## 
## Made by Rayan
## Login   <raihane.akkache@epitech.eu>
## 
## Started on  Wed Jun 14 17:16:54 2017 Rayan
## Last update Sun Jul  2 23:28:38 2017 laurent
##

RM		=	rm -f

SERVER		=	zappy_server

AI		=	zappy_ai

SRC_SE		= 	./server/main.c \
			./server/check_args.c \
			./server/team_fctn.c \
			./server/win_fctn.c \
			./server/take_obj.c \
			./server/game.c \
			./server/egg2.c \
			./server/g_cmd.c \
			./server/g_cmd2.c \
			./server/eggs_fctn.c \
			./server/get_next_line.c \
			./server/my_str_to_wordtab.c \
			./server/fds.c \
			./server/com_gui.c \
			./server/pos.c \
			./server/exec_graphic_cmd.c \
			./server/leave_obj.c \
			./server/incantation.c \
			./server/broadcast.c \
			./server/broadcast2.c \
			./server/cmd1.c \
			./server/cmd2.c \
			./server/tab_cmd.c \
			./server/look.c \
			./server/look2.c \
			./server/moove.c \
			./server/time.c \
			./server/get_team.c \
			./server/new_client.c \
			./server/clients.c \
			./server/check_stones_on_case.c \
			./server/begin_incantation.c \

SRC_AI		=	./ai/main.c		\
			./ai/check_arg.c	\
			./ai/init.c		\
			./ai/read_isset.c	\
			./ai/my_str_to_wordtab.c\
			./ai/algo_ai.c		\
			./ai/my_epure.c		\
			./ai/tab.c		\
			./ai/cmd.c		\
			./ai/cmd2.c		\
			./ai/get.c		\
			./ai/lvl.c		\
			./ai/lvl2.c		\
			./ai/crypt.c		\
			./ai/direction.c	\
			./ai/direction2.c	\
			./ai/take.c		\
			./ai/set.c		\
			./ai/stones.c		\
			./ai/check.c		\

CFLAGS		=  	-g3 -W -Wall -Wextra #-Werror

OBJS_SE		= 	$(SRC_SE:.c=.o)

OBJS_AI		= 	$(SRC_AI:.c=.o)

all:			$(SERVER) $(AI)

$(SERVER):		$(OBJS_SE)
			gcc -o $(SERVER) $(OBJS_SE) -lm

$(AI):			$(OBJS_AI)
			gcc -o $(AI) $(OBJS_AI) -lmy -L.

clean:
			$(RM) $(OBJS_SE) $(OBJS_AI)

fclean: 		clean
			$(RM) $(SERVER) $(AI)

re:			fclean all

.PHONY:			all clean fclean re
