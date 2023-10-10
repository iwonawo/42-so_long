/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:30:42 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/10 13:47:26 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	count_moves(t_data *data)
{
	data->move_count++;
	ft_printf("\033[H\033[J");
	ft_printf("moves: %d\n", data->move_count);
}

void	update_player_position(t_data *data, int current_y, int current_x)
{
	int	prev_y;
	int	prev_x;

	prev_y = data->player_y;
	prev_x = data->player_x;
	if (data->map[current_y][current_x] == '0'
		|| data->map[current_y][current_x] == 'C')
	{
		if (data->map[current_y][current_x] == 'C')
			data->collected++;
		data->map[current_y][current_x] = 'P';
		data->map[prev_y][prev_x] = '0';
		data->player_y = current_y;
		data->player_x = current_x;
		count_moves(data);
	}
	else if (data->map[current_y][current_x] == 'E'
		&& data->collected == data->collectibles)
	{
		data->map[current_y][current_x] = 'P';
		data->map[prev_y][prev_x] = '0';
		count_moves(data);
		success(data);
	}
}

void	move_player(t_data *data, int current_y, int current_x)
{
	int	prev_x;

	prev_x = data->player_x;
	if (current_x > prev_x)
		data->player_move_dir = MOVE_RIGHT;
	else if (current_x < prev_x)
		data->player_move_dir = MOVE_LEFT;
	update_player_position(data, current_y, current_x);
	destroy_images(data);
	render_map(data);
}
