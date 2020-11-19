##
## makefile for Makefile in /home/fortev_g
##
## Made by Gabriel Forteville
## Login   <fortev_g@epitech.net>
##
## Started on  Fri Oct  9 09:59:51 2015 Gabriel Forteville
## Last update Thu Jan  5 10:09:25 2017 Gabriel Forteville
##

NAME	=	menger

SRC 	=	main.c \
			menger.c \
			my_get_nbr.c

OBJ 	=	$(SRC:.c=.o)

CFLAGS 	+= -Wall -Wextra -Werror -std=gnu99 -I./

CC		= gcc

all:	$(NAME)

$(NAME): $(OBJ)
		$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:	fclean all
