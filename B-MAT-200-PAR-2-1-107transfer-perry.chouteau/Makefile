##
## EPITECH PROJECT, 2020
## B-CPE-110-PAR-1-3-pushswap-perry.chouteau
## File description:
## Makefile
##

SRC_MAIN =	sources/main.c

SRC =	sources/principal.c	\
		sources/init.c

SRC_TEST = tests/*.c

OBJ =	$(SRC:.c=.o)	\
		$(SRC_MAIN:.c=.o)


NAME = 107transfer
NAME_TEST = unit_tests

CFLAGS = -Wall -Wextra	\

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C libmy/
	gcc -o $(NAME) $(OBJ) -lm -I libmy/includes/ -L libmy/ -lmy

bonus:
	cp bonus/main.py $(NAME)
	chmod +x $(NAME)

clean:
	rm -rf *~
	cd sources/ && rm -rf *~
	rm -rf *.gcda && rm -rf *.gcno
	rm -rf $(NAME)
	rm -rf unit_tests

fclean: clean
	rm -rf $(OBJ)
	rm -rf $(EXE)
	rm -rf libmy/sources/*.o

re: fclean all

unit_tests:	fclean
	make -C libmy/ 
	gcc -o $(NAME_TEST) $(SRC) $(SRC_TEST) --coverage -lcriterion -lm -I libmy/includes/ -L libmy/ -lmy

tests_run: unit_tests
	./unit_tests
	gcovr --exclude tests/
	gcovr -b --exclude tests/

rm_o:
	rm -rf libmy/sources/*.o

.PHONY: all clean fclean re unit_tests tests_run rm_o
	make fclean