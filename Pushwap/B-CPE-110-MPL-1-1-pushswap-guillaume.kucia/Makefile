##
## EPITECH PROJECT, 2021
## MAKEFILE 101pong
## File description:
## MAKEFILE DE Création d'exécutable
##

CC = gcc

AR = ar src

TARGET = push_swap

CFLAGS = -W -Werror -Wextra -Wall -I/include

CRITERION =

SRC = push_swap.c \
      node/node_push_back.c \
      lib/my_getnbr.c \
      lib/my_put_nbr.c \
      lib/my_putchar.c \
      lib/my_putstr.c \
      lib/my_revstr.c \
      lib/my_strcat.c \
      lib/my_strcmp.c \
      lib/my_strcpy.c \
      lib/my_strdup.c \
      lib/my_strlen.c \
      find_errors.c \
      node/ra.c \
      node/pb.c \
      node/pa.c \
      sort_my_list.c \
	  node/rra.c \
	  print_my_list.c \
	  sort_my_list_loop.c \

OBJ = $(SRC:.c=.o)

.SILENT: $(OBJ)

all : $(TARGET)
	@echo "\033[34m ----------------------------"
	@echo " | -> Plus rien à make {❕} |"
	@echo " ----------------------------\033[0m"

$(TARGET) : $(OBJ)
	@echo "\033[1;92mCréation du binaire.... [$(TARGET)]\033[0m [⏳]"
	@echo "\033[34m"
	@$(CC) -o $(TARGET) $(OBJ) $(CRITERION)
	@echo " | -> $(TARGET) WAS CREATED './$(TARGET)' [🆗]"
	@echo "\033[0m"
	@echo "\033[1;92mLa création de l'éxécutable est terminé ! [✅]\033[0m"

clean :
	clear
	@echo "\033[1;92m\nCleaning....\033[0m [⏳]"
	@echo "\033[34m"
	@$(RM) $(OBJ)
	@echo " | -> ALL CLEAR [🆗]"
	@echo "\033[0m"

fclean : clean
	@echo "\033[1;92mSupression de $(TARGET)\033[0m [⏳]"
	@echo "\033[34m"
	@$(RM) $(TARGET)
	@echo " | -> DONE [🆗]"
	@echo "\033[0m"

re : fclean all
