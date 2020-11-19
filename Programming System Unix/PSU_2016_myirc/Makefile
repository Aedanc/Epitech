##
## Makefile for myirc in /home/pauline/rendu/psu/PSU_2016_myirc
## 
## Made by Pauline Maes
## Login   <maes_p@epitech.eu>
## 
## Started on  Thu May 25 16:09:46 2017 Pauline Maes
## Last update Sun Jun 11 23:23:13 2017 Pauline Maes
##

NAME1		=	server

NAME2		=	client

SRCS1		=	src/server/main.c 		\
			src/server/check_args.c		\
			src/server/manage_error.c	\
			src/server/init_server.c	\
			src/server/create_socket.c	\
			src/server/manage_irc.c		\
			src/server/my_accept.c		\
			src/server/add_client.c		\
			src/server/send_reply.c		\
			src/server/exec_server.c	\
			src/server/exec_nick.c		\
			src/server/exec_list.c		\
			src/server/exec_join.c		\
			src/server/exec_part.c		\
			src/server/exec_users.c		\
			src/server/exec_names.c		\
			src/server/exec_msg.c		\
			src/server/exec_accept_file.c	\
			src/server/in_tab.c		\
			src/server/free_tab.c		\
			src/server/add_to_tab.c		\
			src/server/delete_from_tab.c	\
			src/server/watch_sockets.c	\
			src/server/max_fd.c	\
			src/server/handle_input.c	\

SRCS2		=	src/client/main.c 		\
			src/client/execCommand.c	\
			src/client/free_tab.c		\
			src/client/functab.c		\
			src/client/init.c		\
			src/client/sendMessage.c		\
			src/client/getMessage.c		\
			src/client/my_str_to_word_tab.c	\
			src/client/commands/quit.c	\
			src/client/commands/nick.c	\
			src/client/commands/help.c	\
			src/client/commands/server.c	\

OBJS1		=	$(SRCS1:.c=.o)

OBJS2		=	$(SRCS2:.c=.o)

CC		=	gcc

RM		=	rm -rf

CFLAGS		=	-W -Wall -Wextra -I./include/ -ggdb3

all		:	$(NAME1) $(NAME2)

$(NAME1)	:	$(OBJS1)
			$(CC) -o $(NAME1) $(OBJS1) $(CFLAGS)

$(NAME2)	:	$(OBJS2)
			$(CC) -o $(NAME2) $(OBJS2) $(CFLAGS)

clean		:
			$(RM) $(OBJS1) $(OBJS2)

fclean		:	clean
			$(RM) $(NAME1) $(NAME2)

re		:	fclean all

.PHONY		:	all clean fclean re
