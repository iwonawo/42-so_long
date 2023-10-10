/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:14:42 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/10 14:02:56 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	init_data(t_data *data)
{
	data->map_valid = 0;
	data->img_w = 64;
	data->img_h = 64;
	data->collectibles = 0;
	data->collected = 0;
	data->found_exit = 0;
	data->move_count = 0;
	data->player_move_dir = MOVE_RIGHT;
	data->display_msg = "Wolf is ready to go on an adventure!";
	data->display_color = WHITE;
}

void	find_start_values(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map_row - 1)
	{
		x = 0;
		while (x < data->map_col - 1)
		{
			if (data->map[y][x] == 'P')
			{
				data->player_y = y;
				data->player_x = x;
			}
			else if (data->map[y][x] == 'C')
				data->collectibles++;
			x++;
		}
		y++;
	}
}
