##
## Makefile for  in /home/fortevg/rendu/infographie/gfx_tekgui
## 
## Made by Forteville Gabriel
## Login   <fortevg@epitech.net>
## 
## Started on  Wed Feb 24 22:02:42 2016 Forteville Gabriel
## Last update Sun Feb 28 19:33:02 2016 Forteville Gabriel
##

CC		=	gcc

NAME1		=	tektest

LIB		=	-L/home/${USER}/.froot/lib/ -llapin \
			-L/usr/local/lib \
			-lsfml-audio \
			-lsfml-graphics \
			-lsfml-window \
			-lsfml-system \
			-lstdc++ -ldl \
			-lm

CFLAGS		+=	-rdynamic -W -Wall -ansi -ggdb3 -Werror -pedantic -I/home/${USER}/.froot/include/

SRC1		=	main.c \
			tcore/tekpixel.c \
			tcore/tektext.c \
			tcore/tekfunction.c \
			tekgetpixel.c \

OBJ1		=	$(SRC1:.c=.o)

all:		$(NAME1)

$(NAME1):	$(OBJ1)
		$(CC) $(OBJ1) $(LIB) -o $(NAME1)

clean:
		rm -f $(OBJ1)

fclean:		clean
		rm -f $(NAME1)

re:		fclean all

.c.o:
	$(CC) -c $< -o $@ $(CFLAGS)

