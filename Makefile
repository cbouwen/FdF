NAME = fdf

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address

SRC_DIR = ./src/
SRC = main.c
SRC_FILES = $(addprefix $(SRC_DIR), $(SRC))

LIBFT_DIR = ./lib/Libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a
LIBFT_INC = -I $(LIBFT_DIR)

GNL_DIR = ./lib/Getnextline/
GNL_LIB = $(GNL_DIR)getnextline.a
GNL_INC = -I $(GNL_DIR)

PRINTF_DIR = ./lib/Printf/
PRINTF_LIB = $(PRINTF_DIR)printf.a
PRINTF_INC = -I $(PRINTF_DIR)

all : $(NAME)

$(NAME) : $(LIBFT_LIB) $(PRINTF_LIB) $(GNL_LIB) $(SRC_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) $(LIBFT_LIB) $(PRINTF_LIB) $(GNL_LIB) -o fdf

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(GNL_LIB):
	make -C $(GNL_DIR)

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

clean : 
	make clean -C $(LIBFT_DIR)
	make clean -C $(GNL_DIR)
	make clean -C $(PRINTF_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
