/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:40:45 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/10 13:46:05 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_map_extension(char *str)
{
	int	file_name_len;

	file_name_len = ft_strlen(str);
	if (file_name_len >= 4
		&& ft_strncmp(str + file_name_len - 4, ".ber", 4) == 0)
		return (VALID);
	return (INVALID);
}
