##
## EPITECH PROJECT, 2022
## -----
## File description:
## Makefile
##

SRC = $(shell find ./src/ -type f -name '*.c') \

OBJ = $(SRC:.c=.o)

NAME = 'my_radar'

all: $(NAME)

$(NAME):
	@gcc $(SRC) -lcsfml-graphics -lcsfml-window\
				 -lcsfml-system -lcsfml-audio -lcsfml-network -lm\
	 -Wall -Wno-unused-variable -Wno-unused-parameter\
	 -Wextra -Iinclude -o $(NAME) -g

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
