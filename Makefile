##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make
##

CPPFLAGS=	-I include/
CFLAGS	=	-Wall -Wextra
LDFLAGS =	-L lib/my/ -lmy
UTFLAGS =	-lcriterion --coverage

SRC	=	tests/test_my_printf.c  \

OBJ	=	$(SRC:.c=.o)

NAME	=	unit_tests

all:	$(NAME)

$(NAME): $(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(UTFLAGS)
	./$(NAME)

clean:
	rm -f $(OBJ) vgcore.*
	make clean -C lib/my/

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/my/

re: fclean all
