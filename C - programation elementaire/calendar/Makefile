##
## Makefile for FASTAtools in /home/fortevg/rendu/FASTAtools
##
## Made by Gabriel Forteville
## Login   <fortev_g@epitech.net>
##
## Started on  Mon Jun 20 09:44:44 2016 Gabriel Forteville
## Last update Sat Jul  2 15:08:18 2016 Gabriel Forteville
##

NAME			=	calendar

SRC			=	src/main.c			\
				src/get_data.c			\
				src/add_employee.c		\
				src/add_meeting.c		\
				src/fire_employee.c		\
				src/print_order_name.c		\
				src/print_meeting.c		\

SRC			+=	src/basic/my_str_to_wordtab.c	\
				src/basic/error.c		\
				src/basic/tablen.c		\
				src/basic/freetab.c		\
				src/basic/free_employee.c	\
				src/basic/free_meeting.c	\

OBJ			=	$(SRC:.c=.o)

CFLAGS			+=	-W -Wall -Wextra -I./include/

DEBUG			=	0

ifeq ($(DEBUG),1)
CFLAGS			+=	-g
endif

CC			=	gcc

all:				$(NAME)

$(NAME):			$(OBJ)
				$(CC) -o $(NAME) $(OBJ)

clean:
				rm -rf $(OBJ)

fclean:				clean
				rm -rf $(NAME)

re:				fclean all
