CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = getnextline.a
AR = ar
ARFLAGS = rcs
SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c get_next_line_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re
