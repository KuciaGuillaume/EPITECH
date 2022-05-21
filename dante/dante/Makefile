##
## EPITECH PROJECT, 2021
## B-CPE-110-MPL-1-1-antman-elisa.plas
## File description:
## Makefile
##

GENERATOR = ./generator/generator
SOLVER = ./solver/solver

all : $(GENERATOR) $(SOLVER)

$(GENERATOR) :
	@ make -C generator/ --no-print-directory

$(SOLVER) :
	@ make -C solver/ --no-print-directory

re : fclean all

fclean : clean
	@ make -C generator/ --no-print-directory fclean
	@ make -C solver/ --no-print-directory fclean

clean :
	@ make -C generator/ --no-print-directory fclean
	@ make -C solver/ --no-print-directory clean