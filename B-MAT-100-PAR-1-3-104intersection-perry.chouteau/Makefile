##
## EPITECH PROJECT, 2020
## B-MAT-100-PAR-1-3-104intersection-perry.chouteau
## File description:
## Makefile
##

SRC_IS =	sources/intersection.c	\
			sources/init.c	\
			sources/calcul.c

SRC_PRINTF =	printf_dir/sources/my_printf.c	\
				printf_dir/sources/cond1.c	\
				printf_dir/sources/cond2.c	\
\
				printf_dir/sources/convert_printf.c	\
				printf_dir/sources/putnbr_printf.c	\
				printf_dir/sources/putchar_printf.c	\
				printf_dir/sources/putstr_printf.c	\
				printf_dir/sources/revstr_printf.c

SRC_LIB =	lib_dir/sources/my_compute_power_rec.c	\
			lib_dir/sources/my_compute_square_root.c	\
			lib_dir/sources/my_sqrt.c	\
			lib_dir/sources/my_is_prime.c	\
			lib_dir/sources/my_swap.c	\
			lib_dir/sources/my_find_prime_sup.c	\
			lib_dir/sources/my_isneg.c	\
			lib_dir/sources/my_str_isnum.c	\
			lib_dir/sources/my_sort_int_array.c	\
			lib_dir/sources/my_getnbr.c	\
\
			lib_dir/sources/my_put_nbr.c	\
			lib_dir/sources/my_putchar.c	\
			lib_dir/sources/my_putstr.c	\
			lib_dir/sources/my_strlen.c	\
			lib_dir/sources/my_showstr.c	\
\
			lib_dir/sources/my_str_isalpha.c	\
			lib_dir/sources/my_str_isprintable.c	\
			lib_dir/sources/my_strcmp.c	\
			lib_dir/sources/my_strncmp.c	\
			lib_dir/sources/my_revstr.c	\
			lib_dir/sources/my_str_islower.c	\
			lib_dir/sources/my_str_isupper.c	\
			lib_dir/sources/my_strcapitalize.c	\
			lib_dir/sources/my_strlowcase.c	\
			lib_dir/sources/my_strupcase.c	\
			lib_dir/sources/my_strcpy.c	\
			lib_dir/sources/my_strcat.c	\
			lib_dir/sources/my_strncat.c	\
			lib_dir/sources/my_strncpy.c	\
			lib_dir/sources/my_strstr.c	\
			lib_dir/sources/my_showmen.c

SRC_MATH =	math_dir/sources/def_line_pos.c	\
			math_dir/sources/equadra_lib.c	\
			math_dir/sources/intersection_cone.c	\
			math_dir/sources/intersection_cylindre.c	\
			math_dir/sources/intersection_sphere.c

SRC_TEST = tests/*.c

OBJ =	$(SRC_PRINTF:.c=.o)	\
		$(SRC_LIB:.c=.o)	\
		$(SRC_IS:.c=.o)	\
		$(SRC_MATH:.c=.o)

NAME = 104intersection

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
