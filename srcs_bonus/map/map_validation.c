/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:00:23 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/07 11:45:04 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	map_validation(t_data *data, char *str)
{
	if (!data->map_str)
		data->error_msg = "Error\nMemory allocation failed.";
	else if (check_map_extension(str) == INVALID)
		data->error_msg = "Error\nWrong map file extension, only .ber allowed.";
	else if (check_char(data->map_str) == INVALID)
		data->error_msg = "Error\nInvalid characters used to create a map.";
	else if (check_if_rect(data) == INVALID)
		data->error_msg = "Error\nMap has to be a rectangle.";
	else if (check_min_c(data->map_str) == INVALID)
		data->error_msg = "Error\nNot enough collectibles on the map.";
	else if (check_min_t(data->map_str) == INVALID)
		data->error_msg = "Error\nNot enough traps on the map.";
	else if (check_valid_e_p(data->map_str) == INVALID)
		data->error_msg = "Error\nExactly one Player and Exit allowed.";
	else if (check_walls(data) == INVALID)
		data->error_msg = "Error\nMap has to be surrounded by walls.";
	else if (check_valid_path(data) == INVALID)
		data->error_msg = "Error\nNo valid path to the Exit.";
	else
		data->map_valid = 1;
	free_map_str(data);
}
