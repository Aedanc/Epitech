##
## Makefile for minishell2 in /home/fortev_g
## 
## Made by Gabriel Forteville
## Login   <fortev_g@epitech.net>
## 
## Started on  Fri Oct  9 09:59:51 2015 Gabriel Forteville
## Last update Wed May 11 20:27:57 2016 Forteville Gabriel
##

NAME	=	mysh

SRC 	=	main.c					\
		doshell.c				\
		multi_pipe.c				\
		execute_commande_in_pipe.c		\

SRC	+=	Builtins/my_exit.c			\
		Builtins/my_env.c			\
		Builtins/my_setenv.c			\
		Builtins/my_cd.c			\
		Builtins/my_unsetenv.c			\

SRC	+=	resource/my_putstr.c			\
		resource/my_strlen.c			\
		resource/my_putchar.c			\
		resource/my_strcompare.c		\
		resource/my_get_nbr.c			\
		resource/my_str_to_word_tab.c		\
		resource/my_show_word_tab.c		\
		resource/my_strcpy.c			\
		resource/my_path.c			\
		resource/remalloc_env.c			\
		resource/tow_to_one.c			\
		resource/my_epurstr.c			\
		resource/my_newvarenv.c			\
		resource/my_puterror.c			\
		resource/my_tablen.c			\
		resource/free_tab.c			\
		resource/my_clean_input.c		\
		resource/my_malloc_tab_tab_int.c	\
		resource/my_free_tab_tab_int.c		\
		resource/check_result.c			\
		resource/no_tab.c			\

OBJ 	=	$(SRC:.c=.o)

CC	=	gcc

DEBUG	?=	0

CFLAGS	+=	-W -Wall -Wextra -I./include/

ifeq ($(DEBUG), 1)
CFLAGS	+=	-g -ggdb3
endif

all 	:	$(NAME)

$(NAME)	: 	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)
clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
