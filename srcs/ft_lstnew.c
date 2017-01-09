/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:05:31 by jlepere           #+#    #+#             */
/*   Updated: 2016/09/26 22:51:24 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*list;

	if (!(list = ft_memalloc(sizeof(struct s_list))))
		return (NULL);
	list->content = NULL;
	if (content && (list->content = ft_memalloc(content_size)))
	{
		ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	else
		list->content_size = 0;
	list->next = NULL;
	return (list);
}
