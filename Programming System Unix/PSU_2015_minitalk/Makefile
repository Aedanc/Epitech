##
## Makefile for  in /home/fortevg/rendu/PSU/PSU_2015_minitalk
## 
## Made by Forteville Gabriel
## Login   <fortevg@epitech.net>
## 
## Started on  Mon Feb  1 17:34:59 2016 Forteville Gabriel
## Last update Wed Feb 10 17:14:16 2016 Forteville Gabriel
##

NAMESERVER	=	server/server

NAMECLIENT	=	client/client

SRC		=	src/my_putchar.c \
			src/my_strlen.c \
			src/my_put_nbr_base.c \
			src/my_get_nbr.c \

SRCSERVER	=	server/mainserver.c \

SRCCLIENT	=	client/mainclient.c \

OBJ		=	$(SRC:.c=.o) 

OBJSERVER	=	$(SRCSERVER:.c=.o)

OBJCLIENT	=	$(SRCCLIENT:.c=.o)

CFLAGS		=	-Wall -Wextra

CC		=	gcc

all: $(OBJ) $(NAMESERVER) $(NAMECLIENT)

$(NAMESERVER): $(OBJSERVER)
			$(CC) -o $(NAMESERVER) $(OBJ) $(OBJSERVER)

$(NAMECLIENT): $(OBJCLIENT)
			$(CC) -o $(NAMECLIENT) $(OBJ) $(OBJCLIENT)

clean:
	rm -f $(OBJSERVER)
	rm -f $(OBJCLIENT)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAMECLIENT)
	rm -f $(NAMESERVER)

re: fclean all
