##
## EPITECH PROJECT, 2021
## MAKEFILE 101pong
## File description:
## MAKEFILE DE Création d'exécutable
##

CC = gcc

CFLAGS = -W -Wall -Werror -Wextra

TARGET = amazing
TARGET_CRITERION = unit_tests

WAITING = sleep 0.1

SRC =  swap_elem.c \
	  bubble_sort_array.c \
	  rotate.c \
	  my_amazing_sorter.c \

SRC_CRITERION = swap_elem.c \
	  bubble_sort_array.c \
	  rotate.c \
	  push.c \
	  pop.c \
	  sort_numbers.c \
	  tests/tests_swap.c \
	  tests/tests_bubble.c \
	  tests/tests_rotate.c \
	  tests/tests_push.c \
	  tests/tests_sort_numbers.c \
	  tests/tests_less_numbers.c \

OBJ = $(SRC:.c=.o)

OBJ_CRITERION = $(SRC_CRITERION:.c=.o)

LDFLAGS	= --coverage -lcriterion

.SILENT: $(OBJ)

all : $(TARGET)

$(TARGET) : $(OBJ)
	@echo "\033[1;92mCréation du binaire.... [$(TARGET)]\033[0m"
	@$(WAITING)
	@echo "\033[34m"
	@$(CC) -o $(TARGET) $(OBJ)
	@echo "$(TARGET) WAS CREATED './$(TARGET)'"
	@echo "\033[0m"
	@$(WAITING)
	@echo "\033[1;92mLa création de l'éxécutable est terminé !\n\033[0m"

clean :
	clear
	@echo "\033[1;92m\nCleaning....\033[0m"
	@$(WAITING)
	@echo "\033[34m"
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_CRITERION)
	@$(RM) $(wildcard *.gcno)
	@echo "ALL CLEAR"
	@$(WAITING)
	@echo "\033[0m"

fclean : clean
	@echo "\033[1;92mSupression de $(TARGET)\033[0m"
	@$(WAITING)
	@echo "\033[34m"
	@$(RM) $(TARGET)
	@$(RM) $(TARGET_CRITERION)
	@echo "DONE"
	@$(WAITING)
	@echo "\033[0m"

re : fclean all

ac: re
	@echo "\033[1;92mClear...\033[0m"
	@$(WAITING)
	clear

tests_run: fclean $(TARGET_CRITERION)

$(TARGET_CRITERION) : $(OBJ_CRITERION)
	@echo "\033[1;92mCréation du binaire.... [$(TARGET_CRITERION)]\033[0m"
	@$(WAITING)
	@echo "\033[34m"
	@$(CC) -o $(TARGET_CRITERION) $(OBJ_CRITERION) $(LDFLAGS)
	@echo "$(TARGET_CRITERION) WAS CREATED './$(TARGET_CRITERION)'"
	@echo "\033[0m"
	@$(WAITING)
	@echo "\033[1;92mLa création de l'éxécutable est terminé !\n\033[0m"

infos:
	clear
	@echo "\033[92m\nCommandes :\n\n-Make (Compile la lib)\n-Make clean (Delete seulement la lib)\n-Make fclean (clean + le binaire)\n-Make re (Fclean + Make)\n-Make ac (re + clear)\033[0m"