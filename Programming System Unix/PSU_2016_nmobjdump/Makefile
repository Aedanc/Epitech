##
## Makefile for malloc in /home/hurlu/rendu/
##
## Made by Hugo Willaume
## Login   <hugo.willaume@epitech.eu>
##
## Started on  Tue Jan 31 17:43:33 2017 Hugo Willaume
## Last update Wed Feb 22 17:29:41 2017 Gabriel Forteville
##

NAME_1	=	my_nm

SRC_1	=	nm/main.c

OBJ_1	=	$(SRC_1:.c=.o)

NAME_2	=	my_objdump

SRC_2	=	objdump/main.c

OBJ_2	=	$(SRC_2:.c=.o)

CC 	=	gcc

CFLAGS	+=	-W -Wall -Wextra -Werror -std=gnu99

all :		$(NAME_1) $(NAME_2)

$(NAME_1) : 	$(OBJ_1)
		$(CC) $(CFLAGS) -o $(NAME_1) $(OBJ_1)

$(NAME_2) : 	$(OBJ_2)
		$(CC) $(CFLAGS) -o $(NAME_2) $(OBJ_2)

clean :
		rm -rf $(OBJ_1) $(OBJ_2)

fclean :	 clean
		 rm -rf $(NAME_1) $(NAME_2)

re :		 fclean all

