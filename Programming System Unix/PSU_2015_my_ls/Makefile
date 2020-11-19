##
## makefile for Makefile in /home/fortev_g
## 
## Made by Gabriel Forteville
## Login   <fortev_g@epitech.net>
## 
## Started on  Fri Oct  9 09:59:51 2015 Gabriel Forteville
## Last update Thu Nov 26 14:10:43 2015 Forteville Gabriel
##
NAME	=	my_ls

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
