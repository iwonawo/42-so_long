/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_events_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:39:45 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/09 12:34:50 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

int	has_collectible_neighbor(t_data *data)
{
	int	y;
	int	x;

	y = data->current_y;
	x = data->current_x;
	return (
		data->map[y - 1][x - 1] == 'C' ||
		data->map[y - 1][x] == 'C' ||
		data->map[y - 1][x + 1] == 'C' ||
		data->map[y][x - 1] == 'C' ||
		data->map[y][x + 1] == 'C' ||
		data->map[y + 1][x - 1] == 'C' ||
		data->map[y + 1][x] == 'C' ||
		data->map[y + 1][x + 1] == 'C'
	);
}

int	wolf_is_near(t_data *data)
{
	int	y;
	int	x;

	y = data->map_y;
	x = data->map_x;
	return (
		data->map[y - 1][x - 1] == 'P' ||
		data->map[y - 1][x] == 'P' ||
		data->map[y - 1][x + 1] == 'P' ||
		data->map[y][x - 1] == 'P' ||
		data->map[y][x + 1] == 'P' ||
		data->map[y + 1][x - 1] == 'P' ||
		data->map[y + 1][x] == 'P' ||
		data->map[y + 1][x + 1] == 'P'
	);
}

int	is_walkable(t_data *data)
{
	int	y;
	int	x;

	y = data->current_y;
	x = data->current_x;
	return (
		data->map[y][x] == '0' ||
		data->map[y][x] == 'C' ||
		data->map[y][x] == 'T'
	);
}

int	is_exit_and_collected_all(t_data *data)
{
	int	y;
	int	x;

	y = data->current_y;
	x = data->current_x;
	return (
		data->map[y][x] == 'E' &&
		data->collected == data->collectibles
	);
}
