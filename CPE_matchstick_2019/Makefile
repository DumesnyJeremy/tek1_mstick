##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## ouaidiha
##

NAME	=	matchstick

SRC	=	src/my_my.c \
		src/my_getnbr.c \
		src/my_printf.c \
		src/my_put_nbr_b.c \
		src/my_put_nbr_l.c \
		src/my_put_nbr_lx.c \
		src/my_put_nbr_lxmaj.c \
		src/my_put_nbr_o.c \
		src/my_put_nbr_p.c \
		src/my_put_nbr_u.c \
		src/my_put_nbr_x.c \
		src/my_put_nbr_xmaj.c \
		src/my_strcmp.c \
		src/my_put_nbr.c \
		src/main_stick.c \
		src/get_next_line.c \
		src/check_error.c \
		src/check_pipe.c \
		src/print_map.c \
		src/ia_code.c

OBJ	=	$(SRC:.c=.o)

CFLAGS  +=	-L./ -lmy -I./include -g3

all	:	$(NAME)

$(NAME) :	$(OBJ) $(SRC)
		gcc -o $(NAME) $(OBJ) -g

clean	:
		rm -f $(OBJ)

fclean  :	clean
		rm -f $(NAME)

re	:	fclean all
