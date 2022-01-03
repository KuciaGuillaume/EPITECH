##
## EPITECH PROJECT, 2021
## MAKEFILE 101pong
## File description:
## MAKEFILE DE Création d'exécutable
##

CC = gcc

CFLAGS = -W -Wall -Werror -Wextra

LDFLAGS= -lm

TARGET = 102architect

WAITING = sleep 0.1

SRC = main.c \

OBJ = $(SRC:.c=.o)

.SILENT: $(OBJ)

all : $(TARGET)

$(TARGET) : $(OBJ)
	@echo "\033[1;92mCréation du binaire.... [$(TARGET)]\033[0m"
	@$(WAITING)
	@echo "\033[34m"
	@$(CC) -o $(TARGET) $(OBJ) $(LDFLAGS)
	@echo "$(TARGET) WAS CREATED './$(TARGET)'"
	@echo "\033[0m"
	@sleep 0.5
	@echo "\033[1;92mLa création de l'éxécutable est terminé !\n\033[0m"

clean :
	clear
	@echo "\033[1;92m\nCleaning....\033[0m"
	@$(WAITING)
	@echo "\033[34m"
	@$(RM) $(OBJ)
	@echo "ALL CLEAR"
	@sleep 0.5
	@echo "\033[0m"

fclean : clean
	@echo "\033[1;92mSupression de $(TARGET)\033[0m"
	@$(WAITING)
	@echo "\033[34m"
	@$(RM) $(TARGET)
	@echo "DONE"
	@sleep 0.5
	@echo "\033[0m"

re : fclean all

ac: re
	@echo "\033[1;92mClear...\033[0m"
	@$(WAITING)
	clear

infos:
	clear
	@echo "\033[92m\nCommandes :\n\n-Make (Compile la lib)\n-Make clean (Delete seulement la lib)\n-Make fclean (clean + le binaire)\n-Make re (Fclean + Make)\n-Make ac (re + clear)\033[0m"