##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	my_printf.c	\
		my_printf_functions.c

CFLAGS	=	-I./include/ -Wall -Wextra -Werror

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	mv $(OBJ) ./lib/my/
	make -s -C ./lib/my/
	mv ./lib/$(NAME) .

tests_run:	all
	@find . -name "*.gc*" -delete
	gcc -o unit_tests $(SRC) tests/*.c -L. -lmy $(CFLAGS) --coverage -lcriterion
	./unit_tests
	rm -f unit_tests test*.gc*
	mkidr -p coverage
	mv *.gc* coverage/

debug:	all
	gcc -g main.c $(SRC) $(CFLAGS) -L. -lmy

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all tests_run clean fclean re
