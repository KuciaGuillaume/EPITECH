##
## EPITECH PROJECT, 2021
## MAKEFILE PRINTF
## File description:
## MAKEFILE DE COMPILATION DE LIB
##

AR = ar src

CFLAGS = -g3 -W -Wall -Werror -Wextra

TARGET = libmy.a

WAITING = sleep 0.1

SRC = print_lib/convert_base.c \
	  print_lib/write_unpritable.c \
	  print_lib/more_flags.c \
	  print_lib/check_flags_x.c \
	  print_lib/verif_more_less.c \
	  print_lib/more_steps.c \
	  my_printf.c \
	  lib/my/my_put_nbr.c \
	  lib/my/my_putchar.c \
	  lib/my/my_putstr.c \
	  lib/my/my_revstr.c \
	  lib/my/my_strcmp.c \
	  lib/my/my_strlen.c \
	  lib/my/my_strdup.c

OBJ = $(SRC:.c=.o)

.SILENT: $(OBJ)

all : $(TARGET)

$(TARGET) : $(OBJ)
	@echo "\033[1;92mCréation du binaire.... [$(TARGET)]\033[0m"
	@$(WAITING)
	@echo "\033[34m"
	@$(AR) -o $(TARGET) $(OBJ)
	@echo "$(TARGET) WAS CREATED"
	@echo "\033[0m"
	@sleep 0.5
	@echo "\033[1;92mLa compilation de la lib est terminé !\n\033[0m"

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

clean+: fclean
	clear

infos:
	clear
	@echo "\033[92m\nCommandes :\n\n-Make (Compile la lib)\n-Make clean (Delete seulement la lib)\n-Make fclean (clean + le binaire)\n-Make re (Fclean + Make)\n-Make clean+ (re + clear)\033[0m"