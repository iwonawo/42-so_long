/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:42:01 by iwozniak          #+#    #+#             */
/*   Updated: 2023/07/25 10:07:52 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp_node;

	if (lst && new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		temp_node = *lst;
		while (temp_node->next)
			temp_node = temp_node->next;
		temp_node->next = new;
	}
}
