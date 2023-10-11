/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:36:09 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/11 08:12:12 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	display_background(t_data *data)
{
	data->display_bg = mlx_new_image(data->mlx, data->map_col * 64, TEXT_WIN_H);
	mlx_put_image_to_window(data->mlx, data->win, data->display_bg, 0,
		data->map_row * 64);
}

void	display_moves(t_data *data)
{
	char	*moves_count;

	moves_count = ft_itoa(data->move_count);
	mlx_string_put(data->mlx, data->win, 10, data->map_row * 64 + 22, GRAY,
		"Wolf's moves: ");
	mlx_string_put(data->mlx, data->win, 105, data->map_row * 64 + 22, WHITE,
		moves_count);
	free(moves_count);
}

void	display_sheep_count(t_data *data)
{
	char	*sheep_count;

	sheep_count = ft_itoa(data->collected);
	mlx_string_put(data->mlx, data->win, 10, data->map_row * 64 + 46, GRAY,
		"Sheep captured: ");
	mlx_string_put(data->mlx, data->win, 119, data->map_row * 64 + 46, WHITE,
		sheep_count);
	free(sheep_count);
}

void	display_msg(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 10, data->map_row * 64 + 70,
		data->display_color, data->display_msg);
}

void	render_text(t_data *data)
{
	display_background(data);
	display_moves(data);
	display_sheep_count(data);
	display_msg(data);
}
