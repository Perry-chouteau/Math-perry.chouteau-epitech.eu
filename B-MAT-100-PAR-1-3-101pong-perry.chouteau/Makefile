##
## EPITECH PROJECT, 2020
## Makefile
## File description:## Makefile
##

SRC =	sources/xyz_in_vector_ex1.c	\
	sources/angle_vector_ex7.c	\
	sources/pos_ex5.c	\
	sources/ball_bat_ex6.c	\
	sources/m_vector_ex3.c	\
	sources/sum_vector_ex2.c	\
	sources/diff_vector_ex2.c	\
	sources/norm_vector_ex4.c	\
	sources/main.c

SF1 =	*~	

all:	$(SRC)
	gcc -o 101pong $(SRC) -lm

clean:
	rm -f $(SF1)

fclean:	clean
	rm -f 101pong

re:	fclean all

.PHONY:	all clean fclean re
