##
## Makefile for SBMlparser in /home/fortevg/rendu/SBMLparser
##
## Made by Gabriel Forteville
## Login   <fortev_g@epitech.net>
##
## Started on  Mon Jun 13 11:48:15 2016 Gabriel Forteville
## Last update Tue Jun 14 10:59:04 2016 Gabriel Forteville
##

NAME			=	SBMLparser

SRC				=	src/main.c							\
					src/get_data_from_file.c			\
					src/free_linked_list.c				\
					src/parsing.c						\

SRC				+=	src/print/print_species.c			\
					src/print/print_usage.c				\
					src/print/print_in_alpha_order.c	\

SRC				+=	src/basic/my_strlen.c				\
					src/basic/my_putstr.c				\
					src/basic/my_strncmp.c				\
					src/basic/my_str_to_wordtab.c		\
					src/basic/free_tab.c				\

OBJ				=	$(SRC:.c=.o)

CFLAGS			+=	-W -Wall -Wextra -pedantic -ansi -I./include/

DEBUG			?=	0

ifeq ($(DEBUG),1)
CFLAGS			+=	-g
endif

CC				=	gcc

all:			$(NAME)

$(NAME):		$(OBJ)
				$(CC) -o $(NAME) $(OBJ)

clean:
				rm -rf $(OBJ)

fclean:			clean
				rm -rf $(NAME)

re:				fclean all
