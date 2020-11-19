##
## Makefile for projTester in /home/fortevg/rendu/projTester
## 
## Made by Gabriel Forteville
## Login   <fortev_g@epitech.net>
## 
## Started on  Wed Jun 22 10:21:53 2016 Gabriel Forteville
## Last update Sat Jun 25 16:18:41 2016 Gabriel Forteville
##

NAME			=	projTester

SRC			=	src/main.c			\
				src/parsing.c			\
				src/alphabe_tree.c		\
				src/print_dir.c			\
				src/try_exec.c			\
				src/argment.c			\
				src/execute.c			\

SRC			+=	src/basic/error.c		\
				src/basic/my_strlen.c		\
				src/basic/tablen.c		\
				src/basic/freetab.c		\
				src/basic/my_str_to_wordtab.c	\
				src/basic/my_path.c		\
				src/basic/open_file.c		\

OBJ			=	$(SRC:.c=.o)

CFLAGS			+=	-W -Wall -Wextra -pedantic -ansi -I./include/

DEBUG			?=	0

ifeq ($(DEBUG),1)
CFLAGS			+=	-g
endif

CC			=	gcc

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CC) -o $(NAME) $(OBJ)

clean:
			rm -rf $(OBJ)

fclean:			clean
			rm -rf $(NAME)

re:				fclean all
