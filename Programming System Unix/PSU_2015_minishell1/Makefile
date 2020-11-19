##
## makefile for Makefile in /home/fortev_g
## 
## Made by Gabriel Forteville
## Login   <fortev_g@epitech.net>
## 
## Started on  Fri Oct  9 09:59:51 2015 Gabriel Forteville
## Last update Mon Jan 25 16:08:03 2016 Forteville Gabriel
##

NAME	=	mysh

SRC 	=	main.c \
		doshell.c \
		resource/my_putstr.c \
		resource/my_strlen.c \
		resource/my_putchar.c \
		resource/my_strcompare.c \
		resource/my_get_nbr.c \
		resource/my_str_to_word_tab.c \
		resource/my_show_word_tab.c \
		resource/my_strcpy.c \
		resource/my_struni.c \

OBJ 	=	$(SRC:.c=.o)

CC	=	clang

CFLAGS	=	-Wall -ggdb3 -Wextra -pedantic

all: $(NAME)

$(NAME): $(OBJ)
		(make -C Builtins/Builtinssrc)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
clean:
		rm -f $(OBJ)
		rm -f Builtins/Builtinssrc/my_exit.o
fclean:
		rm -f $(NAME)

re:	fclean clean all
