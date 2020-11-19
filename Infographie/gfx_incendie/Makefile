

NAME1		=	tekcampfirearcade

LIB		=	-L/home/${USER}/.froot/lib/ -llapin \
			-L/usr/local/lib \
			-lsfml-audio \
			-lsfml-graphics \
			-lsfml-window \
			-lsfml-system \
			-lstdc++ -ldl \
			-lm

FLAG		=	-W -Wall -ansi -Werror -pedantic -I/home/${USER}/.froot/include/

SRC1		=	flame/main.c \
			flame/tekpixel.c \
			flame/random.c \
			flame/effect.c \

OBJ1		=	$(SRC1:.c=.o)

all:		$(NAME1)

$(NAME1):	$(OBJ1)
		clang $(OBJ1) $(LIB) -o $(NAME1)

clean:
		rm -f $(OBJ1)

fclean:		clean
		rm -f $(NAME1)

re:		fclean all

.c.o:
	clang -c $< -o $@ $(FLAG)

