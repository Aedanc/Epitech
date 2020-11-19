
NAME		=	tekpaint

LIB		=	-L/home/${USER}/.froot/lib/ -llapin \
			-L/usr/local/lib \
			-lsfml-audio \
			-lsfml-graphics \
			-lsfml-window \
			-lsfml-system \
			-lstdc++ -ldl \
			-lm

FLAG		=	-W -Wall -Werror -ansi -pedantic -g -I/home/${USER}/.froot/include/

SRC		=	src/tmp/tekpaint.c \
			src/tmp/tekline.c \
			src/tmp/tekpixel.c \
			src/tmp/set_color.c \
			src/tmp/tekcircle.c \
			src/tmp/get_buttons.c \
			src/tmp/pencil.c \
			src/tmp/invert_color.c \
			src/tmp/is_button.c \
			src/tmp/is_pallette.c \
			src/tmp/tekgetpixel.c \
			src/tmp/get_color.c \
			src/tmp/draw_line.c \
			src/tmp/get_next_line.c \
			src/tmp/user_loader_saver.c \
			src/tmp/basics.c \
			src/tmp/load_bmp.c \
			src/tmp/load_epi.c \
			src/tmp/save_epi.c \
			src/tmp/save_bmp.c \
			src/tmp/my_strcmp.c \
			src/tmp/file_handling.c \
			src/tmp/tekstretch.c


OBJ		=	$(SRC:.c=.o)

all:		$(NAME)
$(NAME):	$(OBJ)
		clang $(OBJ) $(LIB) -o $(NAME)
clean:
		rm -f $(OBJ)
fclean:		clean
		rm -f $(NAME)
re:		fclean all
.c.o:
	clang -c $< -o $@ $(FLAG)

