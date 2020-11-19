##
## Makefile for  in /home/hurlu/rendu/cpp_santa
## 
## Made by Hugo Willaume
## Login   <willau_h@epitech.net>
## 
## Started on  Sat Jan 14 13:34:25 2017 Hugo Willaume
## Last update Sun Jan 15 09:34:52 2017 Hugo Baldassin
##

NAME = santa

SRC = main_test.cpp \
      src/AObject.cpp \
      src/AToy.cpp \
      src/AWrap.cpp \
      src/Box.cpp \
      src/GiftPaper.cpp \
      src/LittlePony.cpp \
      src/Teddy.cpp \
      src/TablePeNoel.cpp \
      src/Elf.cpp \
      src/ConveyorBelt.cpp \
      src/unitTests.cpp


OBJ = $(SRC:.cpp=.o)

CC = g++

CXXFLAGS = -W -Wall -Wextra -Werror -std=c++03 -I./includes -I./includes/toy \
		-I./includes/containers -I./includes/wrap

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re: fclean all

