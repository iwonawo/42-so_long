/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:37:44 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/10 12:06:23 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	render_wall(t_data *data, int random)
{
	if ((data->map_y == 0 || data->map_y == data->map_row - 1)
		|| (data->map_x == 0 || data->map_x == data->map_col - 1))
		mlx_put_image_to_window(data->mlx, data->win, data->sprites[2],
			data->map_x * IMG_H, data->map_y * IMG_W);
	else
	{
		if (random == 0)
			mlx_put_image_to_window(data->mlx, data->win, data->sprites[1],
				data->map_x * IMG_H, data->map_y * IMG_W);
		else
			mlx_put_image_to_window(data->mlx, data->win, data->sprites[2],
				data->map_x * IMG_H, data->map_y * IMG_W);
	}
}

void	render_collectible(t_data *data, int random)
{
	if (random == 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->sprites[3], data->map_x * IMG_H, data->map_y * IMG_W);
	else
		mlx_put_image_to_window(data->mlx, data->win,
			data->sprites[4], data->map_x * IMG_H, data->map_y * IMG_W);
}

void	render_sheep_scared(t_data *data, int random)
{
	if (random == 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->sprites[9], data->map_x * IMG_H, data->map_y * IMG_W);
	else
		mlx_put_image_to_window(data->mlx, data->win,
			data->sprites[10], data->map_x * IMG_H, data->map_y * IMG_W);
}

void	render_player(t_data *data)
{
	if (data->player_move_dir == MOVE_RIGHT)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->sprites[6],
			data->map_x * IMG_H, data->map_y * IMG_W);
	}
	else if (data->player_move_dir == MOVE_LEFT)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->sprites[7],
			data->map_x * IMG_H, data->map_y * IMG_W);
	}
}

void	render_exit(t_data *data)
{
	if (data->collected == data->collectibles)
		mlx_put_image_to_window(data->mlx, data->win, data->sprites[5],
			data->map_x * IMG_H, data->map_y * IMG_W);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->sprites[1],
			data->map_x * IMG_H, data->map_y * IMG_W);
}
