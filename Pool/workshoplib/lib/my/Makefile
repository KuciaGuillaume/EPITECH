##
## EPITECH PROJECT, 2021
## workshoplib
## File description:
## Makefile
##

CC 	= gcc
FLAGS	= -W -Wall -Wextra -Werror

LIB_SRC = *.c

LIB_OBJ = *.o

TARGET_LIB = libmy.a

all: $(TARGET_LIB)
    $(TARGET_LIB):
	$(CC) -c $(LIB_SRC)
	ar src $(TARGET_LIB) $(LIB_OBJ)

clean:
	rm  -f $(LIB_OBJ)

fclean: clean
	rm  -f $(TARGET_LIB)

re: fclean all
