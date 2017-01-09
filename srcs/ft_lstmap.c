/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:37:18 by jlepere           #+#    #+#             */
/*   Updated: 2016/09/26 23:18:09 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*curr_list;
	t_list	*last_list;
	t_list	*new_list;

	if (!lst || !(*f))
		return (NULL);
	new_list = (*f)(lst);
	last_list = new_list;
	lst = lst->next;
	while (lst)
	{
		curr_list = (*f)(lst);
		last_list->next = curr_list;
		last_list = curr_list;
		lst = lst->next;
	}
	return (new_list);
}
