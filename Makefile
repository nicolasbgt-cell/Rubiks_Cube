NAME = rubiks

CC = gcc 
CFLAGS = -Wall -Wextra -Werror

SRC = main.c\
	cube_init.c\
	display.c\
	move.c\
	shuffle.c\
	solver.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
