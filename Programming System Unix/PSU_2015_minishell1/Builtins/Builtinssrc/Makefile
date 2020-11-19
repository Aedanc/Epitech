##
## Makefile for  in /home/fortevg/rendu/PSU/PSU_2015_minishell1/Builtins/Builtinssrc
## 
## Made by Forteville Gabriel
## Login   <fortevg@epitech.net>
## 
## Started on  Thu Jan  7 14:40:05 2016 Forteville Gabriel
## Last update Sun Jan 24 12:50:05 2016 Forteville Gabriel
##

NAME1	=	exit

SRC1	=	my_exit.c \
		../../resource/my_get_nbr.c \
		../../resource/my_putstr.c \
		../../resource/my_strlen.c \

OBJ1	=	$(SRC1:.c=.o)

CFLAGS	=	-Wall -Wextra -pedantic

CC	=	clang

all:	$(NAME1)

$(NAME1):	$(OBJ1)
	$(CC) $(CFLAGS) -o $(NAME1) $(OBJ1)
	mv exit ..
