/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:23:32 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/07 11:41:52 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

int	check_char(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (INVALID);
	while (str[i])
	{
		if (ft_strchr("01CEPT\n", str[i]))
		{
			if (str[i] == '\n' && str[i + 1] == '\n')
				return (INVALID);
			i++;
		}
		else
			return (INVALID);
	}
	return (VALID);
}

int	check_min_c(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (INVALID);
	while (str[i])
	{
		if (str[i] == 'C')
			return (VALID);
		i++;
	}
	return (INVALID);
}

int	check_valid_e_p(const char *str)
{
	int	i;
	int	count_p;
	int	count_e;

	i = 0;
	count_e = 0;
	count_p = 0;
	if (str == NULL)
		return (INVALID);
	while (str[i])
	{
		if (str[i] == 'E')
			count_e++;
		else if (str[i] == 'P')
			count_p++;
		i++;
	}
	if (count_p == 1 && count_e == 1)
		return (VALID);
	return (INVALID);
}

int	check_if_rect(t_data *data)
{
	int	row_len;
	int	prev_row_len;
	int	i;

	row_len = 0;
	prev_row_len = -1;
	i = 0;
	while (data->map_str[i] != '\0')
	{
		if (data->map_str[i] != '\n')
		{
			row_len++;
			if (data->map_str[i + 1] == '\0' && row_len != prev_row_len)
				return (INVALID);
		}
		else
		{
			if (prev_row_len != -1 && row_len != prev_row_len)
				return (INVALID);
			prev_row_len = row_len;
			row_len = 0;
		}
		i++;
	}
	return (VALID);
}

int	check_walls(t_data *data)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (col < data->map_col)
	{
		if ((data->map[0][col] != '1')
			|| (data->map[data->map_row - 1][col] != '1'))
			return (INVALID);
		col++;
	}
	while (row < data->map_row)
	{
		if ((data->map[row][0] != '1')
			|| (data->map[row][data->map_col - 1] != '1'))
			return (INVALID);
		row++;
	}
	return (VALID);
}
