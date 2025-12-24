NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

SRCS = src/main.c src/monsieur_enfant.c src/path.c src/error_utils.c
BONUS_S = src_bonus/main_bonus.c src_bonus/monsieur_enfant_bonus.c src_bonus/path_bonus.c src_bonus/error_utils_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_B = $(BONUS_S:.c=.o)
INCLUDES = pipex.h
LIBFT_PATH = lol
LIBFT = $(LIBFT_PATH)/libft.a
all: $(NAME)

bonus: .bonus

.bonus: $(OBJS_B) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_B) -L $(LIBFT_PATH) -lft -o $(NAME)
	@touch .bonus

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT_PATH) -lft -o $(NAME)

clean:
	@rm -f $(OBJS) $(OBJS_B)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@rm -f $(NAME) .bonus
	@make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re