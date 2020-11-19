##
## Makefile for makefile minitalk in /home/lecler_1/repository/PSU_2015_minitalk
## 
## Made by Anthony Leclerc
## Login   <lecler_1@epitech.net>
## 
## Started on  Mon Feb  1 14:10:05 2016 Anthony Leclerc
## Last update Sun Mar 20 21:03:36 2016 anthony
##

CC		=	gcc
ERRORS		=	errlog~
NAME		=	scroller_demo_scene

GREEN		=	"\033[1;32m"
RED		=	"\033[1;31m"
CYAN		=	"\033[1;36m"
ENDC		=	"\033[00m"

OK		=	"[OK]"
KO		=	"[KO]"

GRAPH		=	graph/
MISC		=	misc/
ECHO		=	echo
NL		=	"\n---------------------"

LIBLAPIN	=	-L/home/$(USER)/.froot/lib/ -llapin \
			-L/usr/local/lib \
			-lsfml-audio \
			-lsfml-graphics \
			-lsfml-window \
			-lsfml-system \
			-lstdc++ -ldl \
			-lm

SRC		=	main.c \
			plasma/plasma.c \
			scroll/scroll.c \
			scroll/scrolling.c \
			scroll/new_cloud_scroll.c \
			scroll/new_mountain_scroll.c \
			scroll/new_fence_scroll.c \
			scroll/new_text_scroll.c \
			sampler/sampler.c \
			sampler/get_bsf_file.c \
			scrollingtext/scrollingtext.c \
			scrollingtext/basic.c \
			plasma/display_plasma_effect.c \
			plasma/set_color_in_palet.c \
			tekpixel.c

OBJ		= 	$(SRC:.c=.o)

CFLAGS		=	-W -Wall -Wextra -Werror
#CFLAGS		+=	-D LAPIN_ALLOCATOR_OVERLOAD
CFLAGS		+=	-D _DEBUG #debug
INC		=	-Iinclude -I/home/$(USER)/.froot/include/

all: 		$(NAME)

$(NAME): 	$(OBJ)
		@$(CC) -o $(NAME) $(OBJ) $(LIBLAPIN) $(INC) && \
		$(ECHO) $(GREEN) $(OK) $(CYAN)  $@ $(ENDC) $(NL) || \
		$(ECHO) $(RED) $(KO) $(CYAN)  $@ $(ENDC) $(NL)

erase:
		@rm -f $(ERRORS)
clean:		erase
		@rm -f $(OBJ)
		@$(ECHO) Deleting .o files...
fclean: 	clean
		@rm -f $(NAME)
		@$(ECHO) Deleting binary file...
re_:
		@$(ECHO) $(CYAN) Recompiling... $(ENDC)
re: 		re_ fclean all

%.o: 		%.c
		@$(CC) -c $< -o $@  $(CFLAGS) $(LIBLAPIN) $(INC) 2>> $(ERRORS) && \
		$(ECHO) $(GREEN) $(OK) $(RED) $<  $(ENDC) || \
		$(ECHO) $(RED) $(KO) $(RED) $< $(ENDC)

.PHONY: 	erase clean fclean re all
