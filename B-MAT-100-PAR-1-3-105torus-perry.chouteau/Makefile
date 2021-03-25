##
## EPITECH PROJECT, 2020
## B-MAT-100-PAR-1-3-104intersection-perry.chouteau
## File description:
## Makefile
##

SRC_TORUS =	sources/torus.c	\
			sources/method.c

SRC_PRINTF =	printf_dir/sources/my_printf.c	\
				printf_dir/sources/cond1.c	\
				printf_dir/sources/cond2.c	\
\
				printf_dir/sources/convert_printf.c	\
				printf_dir/sources/putnbr_printf.c	\
				printf_dir/sources/putchar_printf.c	\
				printf_dir/sources/putstr_printf.c	\
				printf_dir/sources/revstr_printf.c

SRC_LIB =	lib_dir/sources/my_isneg.c	\
			lib_dir/sources/my_str_isnum.c	\
			lib_dir/sources/my_getnbr.c	\
\
			lib_dir/sources/my_strlen.c	\
			lib_dir/sources/my_strcmp.c	\
			lib_dir/sources/my_putchar.c

SRC_MATH =  math_dir/sources/f_x.c	\
			math_dir/sources/fp_x.c

SRC_TEST = tests/*.c

OBJ =	$(SRC_TORUS:.c=.o)	\
		$(SRC_LIB:.c=.o)	\
		$(SRC_PRINTF:.c=.o)	\
		$(SRC_MATH:.c=.o)


NAME = 105torus

NAME_TEST = unit_tests

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -Wall -Wextra -lm

clean:
	rm -rf *~
	cd sources/ && rm -rf *~
	cd printf_dir/sources/ && rm -rf *~
	cd lib_dir/sources/ && rm -rf *~
	rm -rf *.gcda && rm -rf *.gcno
	rm -rf $(NAME)
	rm -rf unit_tests

fclean: clean
	rm -rf $(OBJ)
	rm -rf $(EXE)

re: fclean all

tests_run:	fclean $(OBJ)
	gcc -o $(NAME_TEST) $(OBJ) $(SRC_TEST) --coverage -l criterion
	./unit_tests
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

.PHONY: all clean fclean re tests_run