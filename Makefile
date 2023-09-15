NAME = fdf

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address

SRC = main.c 

LIBFT_DIR = ./Libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a
LIBFT_INC = -I $(LIBFT_DIR)

GNL_DIR = ./Getnextline/
GNL_LIB = $(GNL_DIR)getnextline.a
GNL_INC = -I $(GNL_DIR)

PRINTF_DIR = ./Printf/
PRINTF_LIB = $(PRINTF_DIR)printf.a
PRINTF_INC = -I $(PRINTF_DIR)

all : $(NAME)

$(NAME) : $(LIBFT_LIB) $(PRINTF_LIB) $(GNL_LIB) $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT_LIB) $(PRINTF_LIB) $(GNL_LIB) -o fdf

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
