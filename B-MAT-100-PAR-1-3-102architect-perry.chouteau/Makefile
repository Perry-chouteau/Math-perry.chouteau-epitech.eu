##
## EPITECH PROJECT, 2020
## B-MAT-100-PAR-1-3-102architect-perry.chouteau
## File description:
## Makefile
##

SRC =	architect.c	\
		sources/init.c	\
		sources/print_str.c	\
		sources/describe.c	\
		sources/test.c	\
		sources/matrice.c

OBJ = $(SRC:.c=.o)

NAME = 102architect

SVFL = *~

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lm -Wall -Wextra

clean:
	rm -rf $(SVFL)

fclean: clean
	rm -rf $(OBJ)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re launch
