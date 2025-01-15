/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:24:12 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/05 12:22:02 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	list = NULL;
	while (lst)
	{
		if (lst->content)
			new_content = f(lst->content);
		if (new_content)
			node = ft_lstnew(new_content);
		if (node == NULL || new_content == NULL)
		{
			del(new_content);
			ft_lstclear(&list, del);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
		lst = lst->next;
	}
	return (list);
}
