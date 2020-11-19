##
## Makefile for Spider in /home/nicolas/Projects/C++/cpp_spider/server
## 
## Made by nicolas
## Login   <nicolas.giacomarosa@epitech.eu>
## 
## Started on  Thu Sep 28 17:49:15 2017 nicolas
## Last update Mon Oct  9 23:35:35 2017 nicolas
##

CC			=	g++

RM			=	rm -f

NAME			=	server

SRC			=	./src/main.cpp			\
				./src/NetworkHandler.cpp	\
				./src/Client.cpp		\
				./src/Command.cpp		\
				./src/Parser/Parser.cpp		\
				./src/log.cpp			\
				./src/sql/Database.cpp		\
				./src/sql/mysql.cpp		\

OBJ			=	$(SRC:.cpp=.o)

CXXFLAGS		=	-I include

LIBS			=	-lboost_system -lboost_thread -lmysqlclient -lssl -lcrypto

DEBUG			?=	0

ifeq ($(DEBUG), 1)
CXXFLAGS		+=	-g -ggdb3
endif

GREEN			=	\033[0;32m

NC			=	\033[0m

%.o:		%.cpp
			$(CC) -std=c++11 -o $(<:.cpp=.o) -c $< $(CXXFLAGS) $(LDFLAGS)
			@echo -e "${GREEN}[OK]${NC} [$<] builded"

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) -std=c++11 -o $(NAME) $(OBJ) ${LIBS}
			@echo -e "${GREEN}[OK]${NC} [$<] linked"

clean:
			$(RM) $(OBJ)
			@echo -e "${GREEN}[OK]${NC} clean"

fclean:		clean
			$(RM) $(NAME)
			@echo -e "${GREEN}[OK]${NC} fclean"

re:			fclean all

.PHONY:	all clean fclean re
