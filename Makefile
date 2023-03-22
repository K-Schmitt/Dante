##
## EPITECH PROJECT, 2022
## my_pushswap
## File description:
## Makefile
##

all : make

make :
	make -C solver
	make -C generator

clean :
	make -C solver clean
	make -C generator clean

fclean :
	make -C solver fclean
	make -C generator fclean

re : fclean all
