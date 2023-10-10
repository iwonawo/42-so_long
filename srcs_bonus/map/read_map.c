/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:27:18 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/06 17:33:25 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	map_to_list(int fd, t_data *data)
{
	char	*line;
	t_list	*map_list;
	t_list	*map_line;

	map_list = NULL;
	map_line = NULL;
	data->map_str = NULL;
	line = get_next_line(fd);
	if (line == NULL)
	{
		ft_printf("Error\nThe map is empty.\n");
		close (fd);
		exit (1);
	}
	while (line != NULL)
	{
		data->map_str = ft_strjoin(data->map_str, line);
		map_line = ft_lstnew(line);
		ft_lstadd_back(&map_list, map_line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	check_before_array(map_list, data, fd);
}

void	check_before_array(t_list *map_list, t_data *data, int fd)
{
	if (check_if_rect(data))
		map_to_array(map_list, data);
	else
	{
		ft_printf("Error\nThe map is not rectangular.\n");
		close (fd);
		free_map_str(data);
		ft_lstclear(&map_list, free);
		exit (1);
	}
}

void	allocate_map_memory(char ***map, int row, int column)
{
	int	i;

	*map = (char **)malloc(row * sizeof(int *));
	if (!(*map))
	{
		ft_printf("Error\nMemory allocation failed.");
		exit (1);
	}
	i = 0;
	while (i < row)
	{
		(*map)[i] = (char *)malloc(column * sizeof(int));
		if (!(*map)[i])
		{
			ft_printf("Error\nMemory allocation failed.");
			exit (1);
		}
		i++;
	}
}

void	map_to_array(t_list *map_list, t_data *data)
{
	int		i;
	int		j;
	char	*line_content;
	t_list	*temp;

	data->map_row = ft_lstsize(map_list);
	data->map_col = ft_strlen(map_list->content) - 1;
	allocate_map_memory(&data->map, data->map_row, data->map_col);
	i = 0;
	while (map_list != NULL)
	{
		line_content = map_list->content;
		j = 0;
		while (line_content[j])
		{
			data->map[i][j] = line_content[j];
			j++;
		}
		i++;
		free(map_list->content);
		temp = map_list;
		map_list = map_list->next;
		free(temp);
	}
}

void	create_map_copy(t_data *data)
{
	int	i;
	int	j;

	allocate_map_memory(&data->map_cpy, data->map_row, data->map_col);
	i = 0;
	while (i < data->map_row)
	{
		j = 0;
		while (j < data->map_col)
		{
			data->map_cpy[i][j] = data->map[i][j];
			j++;
		}
		i++;
	}
}
