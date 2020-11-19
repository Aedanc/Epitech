##
## makefile for Makefile in /home/fortev_g
##
## Made by Gabriel Forteville
## Login   <fortev_g@epitech.net>
##
## Started on  Fri Oct  9 09:59:51 2015 Gabriel Forteville
## Last update Mon Jan  9 17:14:33 2017 Gabriel Forteville
##

NAME	=	my_convert_temp

SRC 	=	main.cpp \

OBJ 	=	$(SRC:.cpp=.o)

CFLAGS 	+=	-Wall -Wextra -Werror -I./ -std=c++03

CC		= g++

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
