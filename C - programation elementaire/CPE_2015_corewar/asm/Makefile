##
## Makefile for makefile in /home/baldas/Prog/base_project
##
## Made by Hugo Baldassin
## Login   <baldas_h@epitech.net>
##
## Started on  Tue Mar 15 17:53:08 2016 Hugo Baldassin
## Last update Thu Mar 24 23:43:08 2016 Hugo Baldassin
##

CC	=	gcc

NAME	=	asm

SRC	=	asm.c 			\
		in_header.c		\
		add_elem.c		\
		add_instruct.c		\
		take_instruct.c		\
		remove_label.c		\
		convert.c		\
		my_cmd_tab.c 		\
		my_tabcpy.c		\
		check_def_label.c	\
		check_cmd.c 		\
		what_type_is_it.c 	\
		epur_tab.c 		\
		epur_line.c 		\
		is_a_label.c 		\
		is_a_command.c 		\
		args_check.c 		\
		fake_printf.c 		\
		is_num.c 		\
		compile_and_pars.c	\
		args_errors.c 		\
		check_param.c 		\
		get_next_line.c		\
		first_word_label.c	\
		check_header.c		\
		add_label.c		\
		check_label_list.c	\
		error_displays.c	\
		file_errors_display.c	\
		final_list_check.c	\
		my_get_long.c		\
		power_of_two.c		\
		op.c

OBJ	=	$(SRC:.c=.o)

LIB	=	-lmy -L./lib/

CFLAGS	=	-W -Wall -Wextra -ansi -pedantic -ggdb3 -I./include

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)
clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
