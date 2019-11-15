##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	my_printf.c			\
		my_printf_number.c		\
		my_printf_str.c			\
		my_printf_pointer.c		\
		my_printf_binary.c		\
		my_printf_octal.c		\
		my_printf_decimal.c		\
		my_printf_hexa_lower.c		\
		my_printf_hexa_upper.c		\
		my_printf_get_infos.c		\
		my_printf_get_modifiers.c	\
		my_printf_flag_errors.c	\
		my_printf_modifier.c		\
		my_putnbr_for_printf.c		\
		my_nbr_len_u.c			\
		convert_base_for_printf.c

CFLAGS	=	-I./include/ -Wall -Wextra -Werror

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	mv $(OBJ) ./lib/my/
	make -s -C ./lib/my/
	mv ./lib/$(NAME) .

tests_run:
	make -s -C ./lib/my/
	@find . -name "*.gc*" -delete
	gcc -o unit_tests $(SRC) tests/*.c -L. -lmy $(CFLAGS) --coverage -lcriterion
	./unit_tests
	rm -f unit_tests test*.gc*
	mkdir -p coverage
	mv *.gc* coverage/

debug:	all
	gcc -g main.c $(SRC) -I./include -L. -lmy

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all lib tests_run clean fclean re
