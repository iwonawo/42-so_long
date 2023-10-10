/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:48:20 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/09 12:12:56 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	update_hunting_msg(t_data *data)
{
	if (data->collected != data->collectibles)
	{
		data->display_msg = "Wolf is hunting...";
		data->display_color = WHITE;
	}
	else
	{
		data->display_msg = "Wolf is full and searching for a cave.";
		data->display_color = GREEN;
	}
}

void	update_msgs_on_move(t_data *data)
{
	if (is_walkable(data))
	{
		update_hunting_msg(data);
		if (has_collectible_neighbor(data))
		{
			data->display_msg = "Sheep has senced your presence.";
			data->display_color = ORANGE;
		}
		if (data->map[data->current_y][data->current_x] == 'C')
		{
			data->display_msg = "Sheep has been eaten!";
			data->display_color = GREEN;
		}
		if (data->map[data->current_y][data->current_x] == 'T')
		{
			data->display_msg = "Wolf fell into a hole!";
			data->display_color = RED;
		}
	}
}
