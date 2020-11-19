

NAME		=	setpixeltest

LIB		=	-L/home/${USER}/.froot/lib/ -llapin \
			-L/usr/local/lib \
			-lsfml-audio \
			-lsfml-graphics \
			-lsfml-window \
			-lsfml-system \
			-lstdc++ -ldl \
			-lm

FLAG		=	 -I/home/${USER}/.froot/include/

SRC		=	main.c \
			teksetpixel.c \
			tekpixel.c \

OBJ		=	$(SRC:.c=.o)

CC		=	clang

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) $(LIB) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.c.o:
	$(CC) -c $< -o $@ $(FLAG)

