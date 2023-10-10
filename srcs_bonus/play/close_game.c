/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:15:01 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/08 14:45:17 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

int	exit_game(t_data *data)
{
	ft_printf("The wolf is peacefully drifting into slumber...");
	free_all_memory(data);
	exit (0);
	return (0);
}

void	success(t_data *data)
{
	data->display_msg = "Wolf is content!";
	data->display_color = GREEN;
	ft_printf("\033[0;32m" "\n\
	╦ ╦╔═╗╦  ╔═╗  ╦╔═╗  ╔═╗╔═╗╔╗╔╔╦╗╔═╗╔╗╔╔╦╗┬\n\
	║║║║ ║║  ╠╣   ║╚═╗  ║  ║ ║║║║ ║ ║╣ ║║║ ║ │\n\
	╚╩╝╚═╝╩═╝╚    ╩╚═╝  ╚═╝╚═╝╝╚╝ ╩ ╚═╝╝╚╝ ╩ o\n\
	\n" "\033[0m");
	free_all_memory(data);
	exit (0);
}

void	failure(t_data *data)
{
	data->display_msg = "Wolf fell into a hole!";
	data->display_color = RED;
	ft_printf("\033[0;31m" "\n\
	╦ ╦╔═╗╦  ╔═╗  ╔═╗╔═╗╦  ╦    ╦╔╗╔╔╦╗╔═╗  ╔═╗  ╦ ╦╔═╗╦  ╔═╗┬\n\
	║║║║ ║║  ╠╣   ╠╣ ║╣ ║  ║    ║║║║ ║ ║ ║  ╠═╣  ╠═╣║ ║║  ║╣ │\n\
	╚╩╝╚═╝╩═╝╚    ╚  ╚═╝╩═╝╩═╝  ╩╝╚╝ ╩ ╚═╝  ╩ ╩  ╩ ╩╚═╝╩═╝╚═╝o\n\
	\n" "\033[0m");
	ft_printf("Try again.");
	free_all_memory(data);
	exit (1);
}
