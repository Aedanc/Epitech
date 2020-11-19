##
## Makefile for nanotekspice in /home/quersi_l/rendu/cpp_nanotekspice
## 
## Made by Laurent QUERSIN
## Login   <quersi_l@epitech.net>
## 
## Started on  Wed Feb 15 12:15:10 2017 Laurent QUERSIN
## Last update Fri Mar  3 21:26:54 2017 Laurent QUERSIN
##


NAME			=	"nanotekspice"

CXX			=	clang++ -Wall -W -std=c++11

RM			=	rm -f

CXXFLAGS		=	-Wall -Wextra
CXXFLAGS		+=	-I includes/ -I includes/chipsets/
LDFLAGS			=

COLOR			=	no

DEBUG			=	no

DFLAGS			=	-Yincludes/ -w80

ifeq ($(CXX), clang++)
CXXFLAGS		+=	-Weverything -Wno-padded
endif

ifneq ($(COLOR), no)
CXXFLAGS		+=	-fdiagnostics-color
endif

ifneq ($(DEBUG), no)
CXXFLAGS		+=	-ggdb3
endif

ifeq ($(DEBUG), no)
LDFLAGS			+=	-s
endif

SRC_NANO		=
include				source_nano.mk

SRC			=	$(SRC_NANO)

OBJ_NANO		=	$(SRC:.cpp=.o)

OBJ			=	$(OBJ_NANO)

all			:	$(NAME)

$(NAME)			:	$(OBJ)
				$(CXX) $(OBJ) -o $(NAME) $(LDFLAGS)

clean			:
				$(RM) $(OBJ)

fclean			:	clean
				$(RM) $(NAME)

re			:	fclean all

%.o			:	%.cpp
				$(CXX) -c $< -o $@ $(CXXFLAGS)

.PHONY			:	all clean fclean re
