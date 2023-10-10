/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:30:42 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/10 12:41:48 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	count_moves(t_data *data)
{
	data->move_count++;
	ft_printf("\033[H\033[J");
	ft_printf("moves: %d\n", data->move_count);
}

void	update_player_position(t_data *data)
{
	int	prev_y;
	int	prev_x;

	prev_y = data->player_y;
	prev_x = data->player_x;
	if (is_walkable(data))
	{
		if (data->map[data->current_y][data->current_x] == 'C')
			data->collected++;
		if (data->map[data->current_y][data->current_x] == 'T')
			failure(data);
		data->map[data->current_y][data->current_x] = 'P';
		data->map[prev_y][prev_x] = '0';
		data->player_y = data->current_y;
		data->player_x = data->current_x;
		count_moves(data);
	}
	else if (is_exit_and_collected_all(data))
	{
		data->map[data->current_y][data->current_x] = 'P';
		data->map[prev_y][prev_x] = '0';
		count_moves(data);
		success(data);
	}
}

void	move_player(t_data *data, int current_y, int current_x)
{
	int	prev_x;

	data->current_y = current_y;
	data->current_x = current_x;
	prev_x = data->player_x;
	if (current_x > prev_x)
		data->player_move_dir = MOVE_RIGHT;
	else if (current_x < prev_x)
		data->player_move_dir = MOVE_LEFT;
	update_msgs_on_move(data);
	update_player_position(data);
	destroy_images(data);
	render_map(data);
}
