##
## EPITECH PROJECT, 2020
## main Makefile
## File description:
## root
##

CC	=	gcc

SRC	=	main.c	\
	$(wildcard src/*.c)

SRC_TEST=

OBJ	=	$(SRC:.c=.o)

INC	=	-I include/

CRITFLAGS=	-lcriterion --coverage

CFLAGS	=	-W -Wall -Wextra -Werror -g3 $(INC)

PTHREAD = -lpthread

NAME=	panoramix

NAME_TEST=	unit_tests

all: $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(PTHREAD)

tests_run: fclean
	gcc -o $(NAME_TEST) $(SRC_TEST) $(INC) $(CFLAGS) $(CRITFLAGS)
	./$(NAME_TEST) --verbose
	gcovr --exclude ./tests
	gcovr -b --exclude ./tests

clean:
	rm -rf *~
	rm -rf src/*~
	rm -rf tests/*~
	rm -rf include/*~
	rm -rf *.gc*

fclean: clean
	rm -rf $(NAME)
	rm -f $(NAME_TEST)
	rm -rf $(OBJ)

re: fclean all