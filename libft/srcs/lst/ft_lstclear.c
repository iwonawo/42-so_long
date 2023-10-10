/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:16:38 by iwozniak          #+#    #+#             */
/*   Updated: 2023/07/25 10:07:37 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_node;
	t_list	*next_node;

	if (lst && del)
	{
		current_node = *lst;
		while (current_node)
		{
			next_node = current_node->next;
			(*del)((current_node)->content);
			free(current_node);
			current_node = next_node;
		}
		*lst = NULL;
	}
}
