##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make
##

CPPFLAGS	=	-I include/
CFLAGS		=	-Wall -Wextra
UTFLAGS 	=	--coverage -lcriterion
DBGFLAGS	=	-ggdb -g3

SRC	=	tests/test_my_printf.c				\
		lib/my/my_putchar.c             	\
		lib/my/my_put_nbr.c 				\
		lib/my/my_putstr.c	 				\
		lib/my/my_revstr.c 					\
		lib/my/my_strlen.c 					\
		lib/my/my_memset.c 					\
		lib/my/my_printf.c					\
		lib/my/my_put_binary.c				\
		lib/my/my_put_hexa.c				\
		lib/my/my_put_long.c				\
		lib/my/my_put_long_long.c			\
		lib/my/my_put_octal.c				\
		lib/my/my_put_unsigned_int.c		\
		lib/my/my_put_unsigned_long.c		\
		lib/my/my_put_unprintable.c			\
		lib/my/my_put_short.c				\
		lib/my/my_put_unsigned_short.c

OBJ	=	$(SRC:.c=.o)

NAME	=	unit_tests

all:	$(NAME)

$(NAME):
	make -C lib/my/
	cp lib/my/libmy.a .

tests_run: CFLAGS += --coverage
tests_run: $(OBJ)
	gcc -o $(NAME) $(OBJ) $(UTFLAGS)
	./$(NAME) $(EXFLAGS)
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

debug: CFLAGS += $(DBGFLAGS)
debug: $(OBJ)
	gcc -o $(NAME) $(OBJ) $(UTFLAGS)
	./$(NAME) $(EXFLAGS)

clean:
	rm -f $(OBJ) vgcore.* tests/*.gcda tests/*.gcno lib/my/*$.gcda lib/my/*.gcno
	make clean -C lib/my/

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/my/

re: fclean all
