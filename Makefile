# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 20:33:48 by ykulkarn          #+#    #+#              #
#    Updated: 2024/04/25 01:59:40 by ykulkarn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -Imlx

HEADER = cub3d.h

LIBFT = libft.a

MLX = ./mlx/libmlx.a

LIBS = -L./libft -lft

NAME = cub3D

RM = rm -f

SRC = ./srcs/main.c ./srcs/error_check.c ./srcs/exit.c ./srcs/file_read.c ./srcs/file_split.c ./srcs/initializer.c \
./srcs/file_check.c ./srcs/utils.c ./srcs/colors.c ./srcs/map.c ./srcs/player.c ./srcs/initial_check.c ./srcs/start_game.c \
./srcs/square.c ./srcs/keys.c ./srcs/ray_casting.c ./srcs/movement.c ./srcs/diagonal.c ./srcs/utils_ray.c ./srcs/pixels.c

OBJS = $(SRC:.c=.o)

all		: $(LIBFT) $(MLX) $(NAME)

$(LIBFT) :
	@make -C libft
	
$(MLX) :
	@make -C ./mlx

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(OBJS) $(LIBS) -Lmlx -lmlx -lXext -lX11 -lm -o $(NAME)
	
clean: 
	$(RM) $(OBJS)
	@make clean -C libft
	@make clean -C ./mlx

fclean: clean
	$(RM) $(NAME)
	@make fclean -C libft
	
re:	fclean all
