/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:27:01 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/10 12:26:26 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	xpm_file_to_image(t_data *data, int index, char *directory)
{
	data->sprites[index] = mlx_xpm_file_to_image(data->mlx, directory,
			&data->img_w, &data->img_h);
}

void	check_if_imgs_exist(t_data *data)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (!data->sprites[i++])
		{
			ft_printf("Error\nNo such sprite found.");
			exit (1);
		}
	}
}

void	prepare_images(t_data *data)
{
	xpm_file_to_image(data, 0, FLOOR_DIR);
	xpm_file_to_image(data, 1, WALL_1_DIR);
	xpm_file_to_image(data, 2, WALL_2_DIR);
	xpm_file_to_image(data, 3, SHEEP_EAT_L);
	xpm_file_to_image(data, 4, SHEEP_EAT_R);
	xpm_file_to_image(data, 5, EXIT_DIR);
	xpm_file_to_image(data, 6, PLAYER_R_DIR);
	xpm_file_to_image(data, 7, PLAYER_L_DIR);
	xpm_file_to_image(data, 8, TRAP);
	xpm_file_to_image(data, 9, SHEEP_SCARED_L);
	xpm_file_to_image(data, 10, SHEEP_SCARED_R);
	check_if_imgs_exist(data);
}

void	put_images_to_window(t_data *data)
{
	int	random_position;

	random_position = (data->map_x * 17 + data->map_y * 31) % 3;
	if (data->map[data->map_y][data->map_x] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->sprites[0],
			data->map_x * IMG_H, data->map_y * IMG_W);
	else if (data->map[data->map_y][data->map_x] == '1')
		render_wall(data, random_position);
	else if (data->map[data->map_y][data->map_x] == 'C')
	{
		if (wolf_is_near(data))
			render_sheep_scared(data, random_position);
		else
			render_collectible(data, random_position);
	}
	else if (data->map[data->map_y][data->map_x] == 'E')
		render_exit(data);
	else if (data->map[data->map_y][data->map_x] == 'P')
		render_player(data);
	else if (data->map[data->map_y][data->map_x] == 'T')
		mlx_put_image_to_window(data->mlx, data->win, data->sprites[8],
			data->map_x * IMG_H, data->map_y * IMG_W);
}

int	render_map(t_data *data)
{
	data->map_y = 0;
	data->map_x = 0;
	prepare_images(data);
	while (data->map_y < data->map_row)
	{
		data->map_x = 0;
		while (data->map_x < data->map_col)
		{
			put_images_to_window(data);
			data->map_x++;
		}
		data->map_y++;
	}
	render_text(data);
	mlx_destroy_image(data->mlx, data->display_bg);
	return (0);
}
