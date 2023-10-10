/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:15:01 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/10 13:47:16 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	exit_game(t_data *data)
{
	ft_printf("The wolf is peacefully drifting into slumber...");
	free_all_memory(data);
	exit (0);
	return (0);
}

void	success(t_data *data)
{
	ft_printf("\033[0;32m" "\n\
	╦ ╦╔═╗╦  ╔═╗  ╦╔═╗  ╔═╗╔═╗╔╗╔╔╦╗╔═╗╔╗╔╔╦╗┬\n\
	║║║║ ║║  ╠╣   ║╚═╗  ║  ║ ║║║║ ║ ║╣ ║║║ ║ │\n\
	╚╩╝╚═╝╩═╝╚    ╩╚═╝  ╚═╝╚═╝╝╚╝ ╩ ╚═╝╝╚╝ ╩ o\n\
	\n" "\033[0m");
	free_all_memory(data);
	exit (0);
}
