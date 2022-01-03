##
## EPITECH PROJECT, 2021
## infinadd
## File description:
## Makefile
##

CC = gcc

BIN = infin_add

SRC = error_404.c \
	  infin_add.c

OBJ = error_404.o \
	  infin_add.o

LIB = ./lib/libmy.a

all : $(BIN)

$(BIN) : $(OBJ) $(LIB)
	$(CC) -o $(BIN) $(OBJ) -L./lib -lmy

$(OBJ) : $(SRC)
	gcc -c $(SRC)

$(LIB) :
	make -C ./lib/my

clean :
	rm -rf $(OBJ)

fclean : cleanf
	make -C ./lib/my/ fclean
	rm -rf $(BIN)
	rm -rf $(LIB)