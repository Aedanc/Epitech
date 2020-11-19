##
## makefile for Makefile in /home/fortev_g
## 
## Made by Gabriel Forteville
## Login   <fortev_g@epitech.net>
## 
## Started on  Fri Oct  9 09:59:51 2015 Gabriel Forteville
## Last update Fri Feb 26 19:11:28 2016 Forteville Gabriel
##

NAME	=	allum1

SRC 	=	main.c \
		checkargu.c \
		printplateau.c \

OBJ 	=	$(SRC:.c=.o)

CC 	=	clang

CFLAGS	=	-pedantic -W -Wall -Wextra -ggdb3

all:		$(NAME)

$(NAME): 	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)  -L./resource/ -lresource

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
