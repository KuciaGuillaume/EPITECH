##
## EPITECH PROJECT, 2021
## MAKEFILE 101pong
## File description:
## MAKEFILE DE Création d'exécutable
##

CC = gcc

TARGET = 42_sh

CFLAGS = -g3 -Wno-unused -Werror -Wextra -Wall

LDFLAGS = -g3 -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-network -lcsfml-audio

CPPFLAGS = -g3 -I./include -I./csfml_engine/include

SRC = $(wildcard csfml_engine/lib/*.c) \
	  $(wildcard csfml_engine/src/*.c) \
	  $(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

.SILENT: $(OBJ)

all : $(TARGET)

$(TARGET) : $(OBJ)
	@make -C lib/my
	@$(CC) -o $(TARGET) -g3 $(OBJ) -g3 $(CFLAGS) $(LDFLAGS) -g3 -lmy -L./lib -lm

clean :
	@make clean -C lib/my
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(TARGET)
	@$(RM) lib/libmy.a


re : fclean all
