/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:31:46 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/06 17:32:52 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

int	explore_map(t_data *data, int y, int x)
{
	if (data->map_cpy[y][x] == 'C')
		data->collected++;
	else if (data->map_cpy[y][x] == 'E')
		data->found_exit = 1;
	if (data->map_cpy[y][x] == '0' || data->map_cpy[y][x] == 'C')
	{
		data->map_cpy[y][x] = 'X';
		if (explore_map(data, y, x + 1) || explore_map(data, y + 1, x)
			|| explore_map(data, y, x - 1) || explore_map(data, y - 1, x))
		{
			return (1);
		}
	}
	if (data->collected == data->collectibles && data->found_exit == 1)
		return (1);
	return (0);
}

int	check_valid_path(t_data *data)
{
	int	start_y;
	int	start_x;

	start_y = data->player_y;
	start_x = data->player_x;
	create_map_copy(data);
	data->map_cpy[start_y][start_x] = '0';
	if (explore_map(data, start_y, start_x))
	{
		free_map_cpy(data);
		data->collected = 0;
		return (VALID);
	}
	free_map_cpy(data);
	data->collected = 0;
	return (INVALID);
}
