/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:59:48 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/10 13:15:25 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

int	window_events(int keycode, t_data *data)
{
	if (keycode == KEY_ESC_MAC || keycode == KEY_ESC_LIN || keycode == 17)
		exit_game(data);
	else if (keycode == KEY_W_LIN || keycode == KEY_UP_LIN
		|| keycode == KEY_W_MAC || keycode == KEY_UP_MAC)
	{
		move_player(data, data->player_y - 1, data->player_x);
	}
	else if (keycode == KEY_S_LIN || keycode == KEY_DOWN_LIN
		|| keycode == KEY_S_MAC || keycode == KEY_DOWN_MAC)
	{
		move_player(data, data->player_y + 1, data->player_x);
	}
	else if (keycode == KEY_A_LIN || keycode == KEY_LEFT_LIN
		|| keycode == KEY_A_MAC || keycode == KEY_LEFT_MAC)
	{
		move_player(data, data->player_y, data->player_x - 1);
	}
	else if (keycode == KEY_D_LIN || keycode == KEY_RIGHT_LIN
		|| keycode == KEY_D_MAC || keycode == KEY_RIGHT_MAC)
	{
		move_player(data, data->player_y, data->player_x + 1);
	}
	return (0);
}

void	open_game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free(data->mlx);
		ft_printf("Error\nCouldn't initialize a game.");
		exit (1);
	}
	data->win = mlx_new_window(data->mlx, data->map_col * IMG_W,
			data->map_row * IMG_H + TEXT_WIN_H, "So Long!");
	if (!data->win)
	{
		free(data->mlx);
		ft_printf("Error\nCouldn't initialize a window.");
		exit (1);
	}
	render_map(data);
	mlx_hook(data->win, 17, 0L, exit_game, data);
	mlx_hook(data->win, 2, 1L << 0, window_events, data);
	mlx_loop(data->mlx);
}
