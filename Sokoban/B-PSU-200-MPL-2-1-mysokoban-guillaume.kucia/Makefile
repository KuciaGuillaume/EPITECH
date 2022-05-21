##
## EPITECH PROJECT, 2021
## MAKEFILE 101pong
## File description:
## MAKEFILE DE Création d'exécutable
##

CC = gcc

TARGET = my_sokoban

CFLAGS = -W -Werror -Wextra -Wall

CPPFLAGS = -I./include

SRC = src/main.c \
		src/open_map.c \
		src/my_sokoban.c \
		src/move_this.c \
		src/move_possible.c \

OBJ = $(SRC:.c=.o)

.SILENT: $(OBJ)

all : $(TARGET)

$(TARGET) : $(OBJ)
	@make -C lib/my
	@$(CC) -o $(TARGET) $(OBJ) $(CFLAGS) -lmy -L./lib -lncurses

clean :
	@make clean -C lib/my
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(TARGET)
	@$(RM) lib/libmy.a


re : fclean all
