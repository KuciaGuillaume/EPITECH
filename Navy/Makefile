##
## EPITECH PROJECT, 2021
## Makefile A NATHAN CATALAN !
## File description:
## task01
##

CC = gcc

AR = ar src

DOSSIER = compil_des_o

CPPFLAGS = -Iinclude/

SRC	= $(wildcard *.c) \
	  $(wildcard lib/*.c) \

OBJ =  $(SRC:.c=.o) \

TARGET = navy

.SILENT: $(OBJ)

all: $(TARGET)

$(TARGET) : $(OBJ)
	@echo "\033[1;99mCréation du binaire... [$(@)]\033[0m"
	@echo "\033[34m"
	@$(CC) -o $(@) $(OBJ) $(CPPFLAGS)
	@echo "\033[1;93mLa création de l'éxécutable est terminé !\n\033[0m"
	@echo "\033[1;95mCréation du dossier...\033[0m"
	@echo "\033[34m"
	@mkdir $(DOSSIER)
	@echo "\033[1;96mDossier {$(DOSSIER)} créé !\n\033[0m"
	@mv -f *.o $(DOSSIER)
	@mv -f lib/*.o $(DOSSIER)
	@echo "\033[1;94mMooving des .o dans $(DOSSIER): OK !\n\033[0m"

fclean :
	@echo "\033[1;90mSupression de $(TARGET)\033[0m"
	@echo "\033[34m"
	@$(RM) $(TARGET)
	@$(RM) lib/*.o
	@$(RM) print_lib/*.o
	@echo "OK\n\033[0m"
	@echo "\033[1;91mSupression du dossier {compil_des_o}\n\033[0m"
	@rm -rf $(DOSSIER)
	@echo "\033[36mDONE\n\033[0m"

re: fclean all