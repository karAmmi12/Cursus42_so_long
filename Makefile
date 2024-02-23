# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kammi <kammi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 14:44:12 by kammi             #+#    #+#              #
#    Updated: 2024/02/23 13:27:38 by kammi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########################################################
## ARGUMENTS

NAME = so_long
ARCHIVE = so_long.a
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -g
MLX= -L lib/mlx -l mlx -I mlx -lXext -lX11 -lm -lz
MAKE_LIB = ar -rcs

##########################################################
## SOURCES

SRCS = srcs/main.c\
		srcs/check_extension.c\
		srcs/get_map.c\
		srcs/check_map.c\
		srcs/exit.c\
		srcs/check_path.c\
		srcs/input.c\
		srcs/put_img.c\
		srcs/move.c\
		srcs/check_wall.c\
		srcs/anim.c\
		srcs/init_game.c\
		srcs/init_map.c\
		srcs/exit_game.c\


OBJS = $(SRCS:.c=.o)

# LIBFT
LIBFT_DIR = lib/libft
LIBFT_MAKE_COMMAND = make -s -C $(LIBFT_DIR)
LIBFT_PATH = $(LIBFT_DIR)/libft.a

# MLX
MLX_DIR = lib/mlx
MLX_MAKE_COMMAND = make -s -C $(MLX_DIR)
MLX_PATH = $(MLX_DIR)/libmlx.a


##########################################################
## RULES

all : $(NAME) $(LIBFT_PATH)

$(NAME) : $(ARCHIVE) $(LIBFT_PATH) $(MLX_PATH)
	$(CC) $(ARCHIVE) $(LIBFT_PATH) $(MLX_PATH) $(MLX) -o $(NAME)

$(ARCHIVE) : $(OBJS)
	$(MAKE_LIB) $(ARCHIVE) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_PATH) :
	$(LIBFT_MAKE_COMMAND)

$(MLX_PATH) :
	$(MLX_MAKE_COMMAND)

clean :
	$(RM) $(OBJS) $(ARCHIVE)
	$(RM) $(OBJS_BONUS)
	$(LIBFT_MAKE_COMMAND) clean
	$(MLX_MAKE_COMMAND) clean

fclean : clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)
	$(LIBFT_MAKE_COMMAND) fclean


re : fclean all

.PHONY : all clean fclean re







