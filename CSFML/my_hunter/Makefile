##
## EPITECH PROJECT, 2021
## 101pong
## File description:
## Makefile
##

CC = gcc

CFLAGS = -g3 -W -Werror -Wextra -Wall -I/include

SFMLFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-network -lcsfml-audio

SRC    =	my_hunter.c \
	  		lib/reload_shotgun.c \
			lib/analyse_event.c \
			lib/create_texture.c \
			lib/create_button_alive.c \
			lib/set_opt_button.c \
			lib/set_move_bullet.c \
			lib/set_gun_action.c \
			lib/set_game_menu.c \
			lib/set_button_action.c \
			lib/set_move_energy.c \
			lib/find_collisions.c \
			lib/set_score.c \
			lib/find_collisions_energy2.c \
			lib/find_collisions_energy3.c \
			lib/verif_life_score.c \
			lib/set_my_score.c \
			set_my_btns.c \
			lib/set_game_event.c \
			lib/initialise_value.c \
			display_my_description.c \
			lib/my_putstr.c \

OBJ = $(SRC:.c=.o)

TARGET = my_hunter

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(SFMLFLAGS)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(TARGET)

re: fclean all