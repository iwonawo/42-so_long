# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwozniak <iwozniak@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/16 13:21:46 by iwozniak          #+#    #+#              #
#    Updated: 2023/10/10 18:30:10 by iwozniak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = so_long \

CFILES_MAP = check_extension \
			check_map \
			check_valid_path \
			init_values \
			map_validation \
			read_map

CFILES_PLAY = cleanup \
			close_game \
			move_events \
			open_game \
			render_images \
			render_map

SRCS_DIR = ./
SRCS_DIR_MAP = ./srcs/map/
SRCS_DIR_PLAY = ./srcs/play/

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(CFILES)))
SRCS_MAP = $(addprefix $(SRCS_DIR_MAP), $(addsuffix .c, $(CFILES_MAP)))
SRCS_PLAY = $(addprefix $(SRCS_DIR_PLAY), $(addsuffix .c, $(CFILES_PLAY)))

OBJS = $(SRCS:.c=.o)
OBJS_MAP = $(SRCS_MAP:.c=.o)
OBJS_PLAY = $(SRCS_PLAY:.c=.o)

CFILES_BONUS = so_long_bonus \

CFILES_MAP_BONUS = check_extension \
			check_map \
			check_traps \
			check_valid_path \
			init_values \
			map_validation \
			read_map

CFILES_PLAY_BONUS = cleanup \
			close_game \
			display_msg \
			move_events_utils \
			move_events \
			open_game \
			render_images \
			render_map \
			update_msg

SRCS_DIR_BONUS = ./
SRCS_DIR_MAP_BONUS = ./srcs_bonus/map/
SRCS_DIR_PLAY_BONUS = ./srcs_bonus/play/

SRCS_BONUS = $(addprefix $(SRCS_DIR_BONUS), $(addsuffix .c, $(CFILES_BONUS)))
SRCS_MAP_BONUS = $(addprefix $(SRCS_DIR_MAP_BONUS), $(addsuffix .c, $(CFILES_MAP_BONUS)))
SRCS_PLAY_BONUS = $(addprefix $(SRCS_DIR_PLAY_BONUS), $(addsuffix .c, $(CFILES_PLAY_BONUS)))

OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJS_MAP_BONUS = $(SRCS_MAP_BONUS:.c=.o)
OBJS_PLAY_BONUS = $(SRCS_PLAY_BONUS:.c=.o)

NAME = so_long
NAME_BONUS = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
AR = ar rcs
RM = rm -f

LIBFT_DIR = ./libft
LIBFT_AR = $(LIBFT_DIR)/libft.a

ifeq ($(shell uname), Linux)
	UNAME := $(shell uname -s)
	MLX_DIR = ./mlx-lin
	MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
	MLX_FLAGS = -L$(MLX_DIR) -lmlx_$(UNAME) -L/usr/lib/X11 -lXext -lX11
	INCLUDES = -I/usr/include -I$(MLX_DIR)
else
	MLX_DIR = ./mlx
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

all: $(NAME)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -I $(MLX_DIR) -c $< -o $@

$(OBJS_MAP): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -I $(MLX_DIR) -c $< -o $@

$(OBJS_PLAY): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -I $(MLX_DIR) -c $< -o $@

$(NAME): $(OBJS) $(OBJS_MAP) $(OBJS_PLAY) $(LIBFT_AR)
	$(CC) $(CFLAGS) $(INCLUDES) -I $(MLX_DIR) -o $(NAME) $(OBJS) $(OBJS_MAP) $(OBJS_PLAY) $(MLX_FLAGS) $(LIBFT_AR)

bonus: $(NAME_BONUS)

$(OBJS_BONUS): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -I $(MLX_DIR) -c $< -o $@

$(OBJS_MAP_BONUS): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -I $(MLX_DIR) -c $< -o $@

$(OBJS_PLAY_BONUS): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -I $(MLX_DIR) -c $< -o $@

$(NAME_BONUS): $(OBJS_BONUS) $(OBJS_MAP_BONUS) $(OBJS_PLAY_BONUS) $(LIBFT_AR)
	$(CC) $(CFLAGS) $(INCLUDES) -I $(MLX_DIR) -o $(NAME_BONUS) $(OBJS_BONUS) $(OBJS_MAP_BONUS) $(OBJS_PLAY_BONUS) $(MLX_FLAGS) $(LIBFT_AR)

$(LIBFT_AR):
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)

clean:
	@make clean -C $(MLX_DIR)
	@make fclean -C $(LIBFT_DIR)
	$(RM) $(OBJS) $(OBJS_MAP) $(OBJS_PLAY) $(OBJS_BONUS) $(OBJS_MAP_BONUS) $(OBJS_PLAY_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re rebonus bonus
