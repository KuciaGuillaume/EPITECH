##
## EPITECH PROJECT, 2021
## MAKEFILE 101pong
## File description:
## MAKEFILE DE Création d'exécutable
##

CC = gcc

TARGET = solver

CFLAGS = -W -Werror -Wextra -Wall -Ofast

CPPFLAGS = -I./include

LDFLAGS = -lmy -L./lib

SRC = $(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

.SILENT: $(OBJ)

all : $(TARGET)

$(TARGET) : $(OBJ)
	@make -C lib/my
	@$(CC) -o $(TARGET) $(OBJ) $(LDFLAGS) -lmy -L./lib

clean :
	@make clean -C lib/my
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(TARGET)
	@$(RM) lib/libmy.a


re : fclean all
