##
## makefile for Makefile in /home/fortev_g
## 
## Made by Gabriel Forteville
## Login   <fortev_g@epitech.net>
## 
## Started on  Fri Oct  9 09:59:51 2015 Gabriel Forteville
## Last update Sun Nov 22 18:45:58 2015 Gabriel Forteville
##
NAME	=	push_swap

SRC 	=	main.c

OBJ 	=	$(SRC:.c=.o)

all:	$(NAME) clean

$(NAME): $(OBJ)
		gcc -ggdb3 -o $(NAME) $(OBJ) -L . libmy.a

clean:
		rm -f $(OBJ)

fclean:
		rm -f $(NAME)

re:	fclean all
