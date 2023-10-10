/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:04:54 by iwozniak          #+#    #+#             */
/*   Updated: 2023/07/25 10:07:06 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstnew_stat(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

static void	ft_lstclear_stat(t_list **lst, void (*del)(void *))
{
	t_list	*current_node;
	t_list	*next_node;

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

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*current_node;
	t_list	*next_node;

	if (!lst || !f || !del)
		return (NULL);
	new_list = ft_lstnew_stat((*f)(lst->content));
	if (!new_list)
		return (NULL);
	current_node = new_list;
	lst = lst->next;
	while (lst)
	{
		next_node = ft_lstnew_stat((*f)(lst->content));
		if (!next_node)
		{
			ft_lstclear_stat(&new_list, del);
			return (NULL);
		}
		current_node->next = next_node;
		current_node = next_node;
		lst = lst->next;
	}
	return (new_list);
}
