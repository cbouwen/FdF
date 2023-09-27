CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = printf.a
AR = ar
ARFLAGS = rcs
SRCS = printf.c printf_p.c printf_utils.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re
