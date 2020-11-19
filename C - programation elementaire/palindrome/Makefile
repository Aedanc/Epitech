##
## Makefile for palindrome in /home/fortevg/rendu/palindrome
##
## Made by Gabriel Forteville
## Login   <fortev_g@epitech.net>
##
## Started on  Wed Jun 15 21:27:19 2016 Gabriel Forteville
## Last update Wed Jun 15 21:27:57 2016 Gabriel Forteville
##


NAME			=	palindrome

SRC				=	src/main.c						\
					src/parsing.c					\
					src/print_usage.c				\
					src/find_palindrom.c			\
					src/find_origins.c				\

SRC				+=	src/basic/error.c				\
					src/basic/revstr.c				\
					src/basic/add_str.c				\
					src/basic/intlen.c				\
					src/basic/int_to_str.c			\

OBJ				=	$(SRC:.c=.o)

CFLAGS			+=	-W -Wall -Wextra -pedantic -ansi -I./include/

DEBUG			?=	0

ifeq ($(DEBUG),1)
CFLAGS			+=	-g
endif

CC				=	gcc

all:				$(NAME)

$(NAME):			$(OBJ)
					$(CC) -o $(NAME) $(OBJ)

clean:
					rm -rf $(OBJ)

fclean:				clean
					rm -rf $(NAME)

re:					fclean all
