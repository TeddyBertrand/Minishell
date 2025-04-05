##
## EPITECH PROJECT, 2024
## Pref
## File description:
## Makefile
##

SRC	=	$(shell find -name "*.c" ! -name "unit_tests.c")
OBJ	=	$(SRC:.c=.o)

SRC_UNIT_TEST	=	$(shell find -name "*.c" ! -name "main.c")
OBJ_UNIT_TEST	=	$(SRC_UNIT_TEST:.c=.o)

CFLAGS	=	-W -Wall -Wextra -g3
CPPFLAGS	=	-I includes/

LDFLAGS	=	-lcriterion --coverage -lm

NAME	=	mysh
NAME_TEST	=	unit_tests

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_UNIT_TEST)
	find -name "*.gcno" -delete
	find -name "*.gcda" -delete

fclean: clean
	$(RM) $(NAME) $(NAME_TEST)
	$(RM) a.out

re: fclean all

tests_run: fclean $(NAME_TEST)
	./$(NAME_TEST)
	gcovr . --exclude tests/
	gcovr . --exclude tests/ --txt-metric branch

$(NAME_TEST): CFLAGS += $(LDFLAGS)

$(NAME_TEST): $(OBJ_UNIT_TEST)
	$(CC) -o $(NAME_TEST) $(OBJ_UNIT_TEST) $(LDFLAGS)
