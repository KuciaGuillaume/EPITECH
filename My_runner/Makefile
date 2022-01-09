##
## EPITECH PROJECT, 2021
## MAKEFILE 101pong
## File description:
## MAKEFILE DE Création d'exécutable
##

CC = gcc

AR = ar src

CFLAGS = -g3 -W -Werror -Wextra -Wall -I/include

LDFLAGS= -g3 -ggdb -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-network -lcsfml-audio

TARGET = my_runner

WAITING = sleep 0

SRC = my_runner.c \
	  lib/create_obj_PushItToList.c \
	  lib/destroy_object.c \
	  lib/add_node.c \
	  game_event.c \
	  lib/draw_object.c \
	  lib/my_strcmp.c \
	  lib/my_strlen.c \
	  lib/rect_type_3.c \
	  lib/move_type1-2.c \
	  lib/box_button.c \
	  lib/rect_type_10.c \
	  lib/reset_perso.c \
	  load_map.c \
	  lib/set_objects_1.c \
	  lib/set_objects_2.c \
	  lib/my_putstr.c \
	  lib/set_assets_2.c \
	  lib/jump.c \
	  lib/rect_life.c \
	  lib/initiate_window.c \
	  lib/my_calloc.c \
	  lib/my_itoa.c \
	  lib/draw_score.c \
	  lib/get_collisions_nothing.c \
	  lib/informations.c \
	  lib/draw_object_2.c \
	  lib/intersection.c \
	  lib/my_getnbr.c \
	  lib/read_write_score.c \
	  lib/set_difficulty.c \
	  lib/set_assets_nothing_up.c \
	  game_event_maps.c \

OBJ = $(SRC:.c=.o)

.SILENT: $(OBJ)

all : $(TARGET)
	@echo "\033[34m ----------------------------"
	@echo " | \033[40m-> Plus rien à make {❕}\033[00m\033[34m |"
	@echo " ----------------------------\033[0m"

$(TARGET) : $(OBJ)
	@echo "\033[1;92mCréation du binaire.... [$(TARGET)]\033[0m [⏳]"
	@echo "\033[34m"
	@$(CC) -o $(TARGET) $(OBJ) $(LDFLAGS)
	@echo " | -> \033[35m[$(TARGET)]\033[34m WAS CREATED './$(TARGET)' [🆗]"
	@echo "\033[0m"
	@echo "\033[1;92mLa création de l'éxécutable est terminé ! [✅]\033[0m"

clean :
	@echo "\033[1;92m\nCleaning....\033[0m [⏳]"
	@echo "\033[34m"
	@$(RM) $(OBJ)
	@echo " | -> ALL CLEAN [🆗]"
	@echo "\033[0m"

fclean : clean
	@echo "\033[1;92mSupression de $(TARGET)\033[0m [⏳]"
	@echo "\033[34m"
	@$(RM) $(TARGET)
	@echo " | -> DONE [🆗]"
	@echo "\033[0m"

re : fclean all
