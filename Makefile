NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c mr_enfant.c path_utils.c path.c libft.c
OBJS = $(SRCS:.c=.o)
INCLUDES = pipex.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

