/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:19:01 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/10 18:30:29 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
// # include "mlx-lin/mlx.h"
# include "libft/includes/libft.h"

# define IMG_H			64
# define IMG_W			64

# define WALL_1_DIR		"./assets/sprites/bush1.xpm"
# define WALL_2_DIR		"./assets/sprites/bush2.xpm"
# define FLOOR_DIR		"./assets/sprites/grass.xpm"
# define COLL_1_DIR		"./assets/sprites/collect_left.xpm"
# define COLL_2_DIR		"./assets/sprites/collect_right.xpm"
# define EXIT_DIR		"./assets/sprites/cave.xpm"
# define PLAYER_R_DIR	"./assets/sprites/wolf_gray_right.xpm"
# define PLAYER_L_DIR	"./assets/sprites/wolf_gray_left.xpm"

# define KEY_W_LIN		119
# define KEY_S_LIN		115
# define KEY_A_LIN		97
# define KEY_D_LIN		100

# define KEY_W_MAC		13
# define KEY_S_MAC		1
# define KEY_A_MAC		0
# define KEY_D_MAC		2

# define KEY_UP_LIN		65362
# define KEY_DOWN_LIN	65364
# define KEY_LEFT_LIN	65361
# define KEY_RIGHT_LIN	65363

# define KEY_UP_MAC		126
# define KEY_DOWN_MAC	125
# define KEY_LEFT_MAC	123
# define KEY_RIGHT_MAC	124

# define KEY_ESC_MAC	53
# define KEY_ESC_LIN	65307
# define EXIT_BTN		17

# define MOVE_LEFT		1
# define MOVE_RIGHT		2

# define VALID			1
# define INVALID		0

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	*map_str;
	char	**map;
	char	**map_cpy;
	int		map_row;
	int		map_col;
	int		map_y;
	int		map_x;
	int		player_y;
	int		player_x;
	int		player_move_dir;
	void	*sprites[8];
	int		img_w;
	int		img_h;
	int		collectibles;
	int		collected;
	int		move_count;
	int		found_exit;
	int		map_valid;
	char	*error_msg;
}			t_data;

/* ************************************************************************** */
/*                                 MAP                                        */
/* ************************************************************************** */

/* ./srcs/map/check_extension.c */
int		check_map_extension(char *str);

/* ./srcs/map/check_map.c */
int		check_char(const char *str);
int		check_min_c(const char *str);
int		check_valid_e_p(const char *str);
int		check_if_rect(t_data *data);
int		check_walls(t_data *data);

/* ./srcs/map/check_valid_path.c */
int		explore_map(t_data *data, int y, int x);
int		check_valid_path(t_data *data);

/* ./srcs/map/init_values.c */
void	init_data(t_data *data);
void	find_start_values(t_data *data);

/* ./srcs/map/map_validation.c */
void	map_validation(t_data *data, char *str);

/* ./srcs/map/read_map.c */
void	map_to_list(int fd, t_data *data);
void	check_before_array(t_list *list, t_data *data, int fd);
void	allocate_map_mem(char ***map, int row, int column);
void	map_to_array(t_list *list, t_data *data);
void	create_map_copy(t_data *data);

/* ************************************************************************** */
/*                                 PLAY                                       */
/* ************************************************************************** */

/* ./srcs/play/cleanup.c */
void	free_map(t_data *data);
void	free_map_cpy(t_data *data);
void	free_map_str(t_data *data);
void	destroy_images(t_data *data);
void	free_all_memory(t_data *data);

/* ./srcs/play/close_game.c */
int		exit_game(t_data *data);
void	success(t_data *data);

/* ./srcs/play/move_events.c */
void	count_moves(t_data *data);
void	update_player_position(t_data *data, int current_y, int current_x);
void	move_player(t_data *data, int current_y, int current_x);

/* ./srcs/play/open_game.c */
void	open_game(t_data *data);
int		window_events(int keycode, t_data *data);

/* ./srcs/play/render_images.c */
void	render_wall(t_data *data, int random);
void	render_collectible(t_data *data, int random);
void	render_player(t_data *data);
void	render_exit(t_data *data);

/* ./srcs/play/render_map.c */
void	xpm_file_to_image(t_data *data, int index, char *directory);
void	check_if_imgs_exist(t_data *data);
void	prepare_images(t_data *data);
void	put_images_to_window(t_data *data);
void	render_map(t_data *data);

#endif
