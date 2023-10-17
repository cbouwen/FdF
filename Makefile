NAME = fdf

CC = gcc
CFLAGS = -g
MLX_FLAGS = -L /usr/lib -l Xext -l X11 -l m -l z

SRC_DIR = ./src/
SRC = main.c info.c parse.c free.c window_utils.c print.c bresenham.c
SRC_FILES = $(addprefix $(SRC_DIR), $(SRC))

HEADER = ./inc/fdf.h ./mlx_linux/mlx.h ./mlx_linux/mlx_int.h

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

$(NAME) : $(LIBFT_LIB) $(PRINTF_LIB) $(GNL_LIB) $(SRC_FILES) $(HEADER)
#	  gcc -g -Wall -Wextra -Werror ./src/main.c ./inc/fdf.h -L ./mlx_linux/ -L ./mlx_linux/ -L ./lib/Getnextline/ -L ./lib/Printf/ -L ./lib/Libft/ -l mlx -l mlx_Linux -l getnextline -l printf -l ft -L /usr/lib -l Xext -l X11 -l m -l z -o fdf
	$(CC) $(CFLAGS) $(SRC_FILES) $(HEADER) -L ./mlx_linux/ -l mlx_Linux -L ./mlx_linux/ -l mlx $(LIBFT_LIB) $(PRINTF_LIB) $(GNL_LIB) $(MLX_FLAGS) -o $(NAME)

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
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(GNL_DIR)
	make fclean -C $(PRINTF_DIR)
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
