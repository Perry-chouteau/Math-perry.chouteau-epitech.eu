##
## EPITECH PROJECT, 2020
## B-CPE-110-PAR-1-3-pushswap-perry.chouteau
## File description:
## Makefile
##

SRC =	sources/my_str_isnum.c	\
		sources/my_strcmp.c	\
		sources/str_to_word_array.c	\
		sources/my_strlen.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)