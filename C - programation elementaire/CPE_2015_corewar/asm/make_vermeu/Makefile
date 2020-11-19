##
## Makefile for Makefile in /home/vermeu_v/Documents/cpe/CPE_2015_corewar/asm/vermeu/
##
## Made by vermeu_v
## Login   <valerian.vermeulen@epitech.eu>
##
## Started on  Mon Mar 21 18:18:34 2016 vermeu_v
## Last update Thu Mar 24 15:19:50 2016 vermeu_v
##

NAME	=	convert

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-W -Wall -Wextra -Werror 
CFLAGS	+=	-ansi -pedantic
CFLAGS	+=	-I../../include
CFLAGS	+=	-I./include

LDFLAGS	=

SRC	=	convert.c \
		my_cmd_tab.c \
		../../VM/src/get_next_line.c \
		../../VM/src/basics/my_getnbr.c \
		../../VM/src/basics/my_strcmp.c \

OBJ	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all
