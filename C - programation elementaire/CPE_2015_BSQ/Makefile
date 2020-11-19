##
## makefile for Makefile in /home/fortev_g
## 
## Made by Gabriel Forteville
## Login   <fortev_g@epitech.net>
## 
## Started on  Fri Oct  9 09:59:51 2015 Gabriel Forteville
## Last update Sat Dec 19 22:35:18 2015 Forteville Gabriel
##

NAME	=	bsq

SRC 	=	main.c \
		resource/my_get_nbr.c \
		resource/my_intlen.c \
		now_find_the_square.c \
		now_put_the_square.c \

OBJ 	=	$(SRC:.c=.o)

CC 	=	clang

CFLAGS	=	-pedantic -W -Wall -Wextra -ggdb3

all:	$(NAME) clean

$(NAME): $(OBJ)
		$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:
		rm -f $(NAME)

re:	fclean all
