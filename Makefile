CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ./src/push_swap.c \
       ./src/ft_utlis.c \
       ./src/ft_validate_num.c \
       ./src/ft_string_val.c \
       ./src/ft_free_error.c \
       ./src/ft_min_swap.c \
       ./src/ft_instruct.c \
       ./src/ft_radix.c
INCLUDES = -I./include
OBJS = $(SRCS:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

