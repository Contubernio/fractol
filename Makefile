# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albealva <albealva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 14:10:00 by albealva          #+#    #+#              #
#    Updated: 2024/06/27 14:12:51 by albealva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=leak
NAME = fractol

SRC_PATH = src/
OBJ_PATH = obj/

SRC = main.c \
	init.c hooks.c mandelbrot.c julia.c tricorn.c validation.c \
	utils.c utils2.c init2.c hooks2.c validation2.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
INCS = -I includes/ -I ./mlx/

MLX_PATH = ./mlx/
MLX_LIB = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c Makefile includes/fractol.h
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_LIB)

clean:
	rm -rf $(OBJ_PATH)
	$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re