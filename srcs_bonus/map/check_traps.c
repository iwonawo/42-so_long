/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_traps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:42:09 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/07 11:42:45 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

int	check_min_t(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (INVALID);
	while (str[i])
	{
		if (str[i] == 'T')
			return (VALID);
		i++;
	}
	return (INVALID);
}
