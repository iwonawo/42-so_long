/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:18:44 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/06 16:15:34 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;

	if (argc != 2)
		return (ft_printf("Error\nAccepts exactly 2 arguments."), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (perror("Error\nFailed to open map file"), 1);
	map_to_list(fd, &data);
	init_data(&data);
	find_start_values(&data);
	map_validation(&data, argv[1]);
	if (data.map_valid)
		open_game(&data);
	else
	{
		ft_putstr(data.error_msg);
		free_map(&data);
		exit (0);
	}
	free_map(&data);
	return (0);
}
