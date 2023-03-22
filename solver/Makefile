##
## EPITECH PROJECT, 2022
## solver
## File description:
## Makefile
##

CC = gcc

CFLAGS = -W -Wall -Wextra

INCLUDES = -I../includes

LFLAGS =

LIBS =

SRC_PATH =

SRCS_NAME = *.c

MAIN = solver

SRCS = $(wildcard $(patsubst %, $(SRC_PATH)%, $(SRCS_NAME)))

OBJS = $(SRCS:.c=.o)

all : $(MAIN)

$(MAIN) : $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.c.o :
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean :
	$(RM) $(OBJS) *~

fclean : clean
	$(RM) $(MAIN)

re : fclean all
