##
## Makefile for  in /home/hurlu/rendu/CPE_2015_corewar/VM
## 
## Made by Hugo Willaume
## Login   <willau_h@epitech.net>
## 
## Started on  Tue Mar 22 13:23:58 2016 Hugo Willaume
## Last update Sun Mar 27 18:56:55 2016 Hugo Willaume
##

NAME	=	corewar

SRC	=	main.c \
		../op.c \
		src/get_next_line.c \
		src/basics/my_putchar.c \
		src/basics/my_putstr.c \
		src/basics/my_strlen.c \
		src/basics/my_putnbr.c\
		src/basics/my_strdup.c \
		src/basics/my_getnbr.c \
		src/basics/my_realloc.c \
		src/basics/my_strcmp.c \
		src/basics/my_strncmp.c \
		src/basics/my_str_append.c \
		src/basics/my_calloc.c \
		src/basics/init_arrays.c \
		src/basics/is_not_in.c \
		src/basics/my_put_nbr_base.c \
		src/parsing.c \
		src/read_dot_cor.c \
		src/big_read_dot_cor.c \
		src/init_arena_champs.c \
		src/init_champs_numbers.c \
		src/init_champs_adresses.c \
		src/place_default_champs.c \
		src/big_endian.c \
		src/dump_arena.c \
		src/checkchamp.c\
		src/cycle.c \
		src/put_result.c \
		src/freechamp.c \
		src/instructions/live.c \
		src/instructions/ld.c \
		src/instructions/st.c \
		src/instructions/add.c \
		src/instructions/sub.c \
		src/instructions/and.c \
		src/instructions/or.c \
		src/instructions/xor.c \
		src/instructions/zjmp.c \
		src/instructions/ldi.c \
		src/instructions/sti.c \
		src/instructions/fork.c \
		src/instructions/lld.c \
		src/instructions/lldi.c \
		src/instructions/lfork.c \
		src/instructions/aff.c \
		src/instructions/readoctecodage.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -ansi -pedantic -I ../include/. -g

CC 	=	gcc

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		@$(CC) -o $(NAME) $(OBJ)
clean	:
		rm -f $(OBJ)
fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
