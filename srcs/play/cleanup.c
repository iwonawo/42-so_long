/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:50:38 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/10 13:20:49 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map != NULL)
	{
		while (i < data->map_row)
			free(data->map[i++]);
		free(data->map);
		data->map = NULL;
	}
}

void	free_map_cpy(t_data *data)
{
	int	i;

	i = 0;
	if (data->map_cpy != NULL)
	{
		while (i < data->map_row)
			free(data->map_cpy[i++]);
		free(data->map_cpy);
		data->map_cpy = NULL;
	}
}

void	free_map_str(t_data *data)
{
	free(data->map_str);
	data->map_str = NULL;
}

void	destroy_images(t_data *data)
{
	int	i;

	i = 0;
	while (i < 8)
		mlx_destroy_image(data->mlx, data->sprites[i++]);
}

void	free_all_memory(t_data *data)
{
	destroy_images(data);
	free_map(data);
	mlx_destroy_window(data->mlx, data->win);
	// mlx_destroy_display(data->mlx);
	free(data->mlx);
}
