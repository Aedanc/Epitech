##
## Makefile for  in /home/fortevg/rendu/PSU/PSU_2015_my_select
## 
## Made by Forteville Gabriel
## Login   <fortevg@epitech.net>
## 
## Started on  Mon Dec  7 17:15:43 2015 Forteville Gabriel
## Last update Wed Dec  9 15:03:41 2015 Forteville Gabriel
##

NAME	=	my_select

SRC 	=	main.c \
	 	resource/my_put_in_list.c \
		resource/my_putstr.c \
		resource/my_strlen.c \
		resource/my_putchar.c \

OBJ 	=	$(SRC:.c=.o)

CFLAGS	=	-ggdb3 -Wextra -Werror -pedantic -Wall

CC	=	clang

all:	$(NAME) clean

$(NAME): $(OBJ)
		 $(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lncurses

clean:
		rm -f $(OBJ)

fclean:
		rm -f $(NAME)

re:	fclean all
