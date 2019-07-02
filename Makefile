##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## Makefile for synthesis pool
##

SRC = 	src/main.c		\
		src/base.c		\
		src/error.c		\
		src/flag_p.c	\
		src/usefull_functions.c \
		src/palindrome.c

NAME = palindrome

OBJ = $(SRC:.c=.o)

CFLAGS = -g3 -Iinclude -Wall -Wextra

all : $(NAME)

$(NAME):	$(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
