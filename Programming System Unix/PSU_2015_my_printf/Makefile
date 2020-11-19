##
## makefile for Makefile in /home/fortev_g
## 
## Made by Gabriel Forteville
## Login   <fortev_g@epitech.net>
## 
## Started on  Fri Oct  9 09:59:51 2015 Gabriel Forteville
## Last update Mon Nov 16 11:28:00 2015 Gabriel Forteville
##
NAME	=	libmy.a

SRC 	=	my_isneg.c \
		my_putchar.c \
		my_put_nbr.c \
		my_get_nbr.c \
		my_putstr.c \
		my_swap.c \
		my_strlen.c \
		sum_stdarg.c \
		disp_stdarg.c \
		my_put_nbr_base.c \
		my_put_nbr_base_uns.c\
		my_printf.c \
		my_put_pointer_base_long.c \
		my_putstrflagS.c

OBJ 	=	$(SRC:.c=.o)

all:	$(NAME) clean

$(NAME): $(OBJ)
		ar rc libmy.a $(OBJ)

clean:
		rm -f $(OBJ)

fclean:
		rm -f $(NAME)

re:	fclean all
