/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 09:57:49 by jlepere           #+#    #+#             */
/*   Updated: 2016/11/03 23:51:44 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	int		begin;
	size_t	index;
	size_t	size;

	if (!s || !ft_strlen(s))
		return (ft_strdup("\0"));
	size = 0;
	index = 0;
	begin = -1;
	while (s[index])
	{
		if (s[index] != ' ' && s[index] != '\n' && s[index] != '\t')
		{
			if (begin < 0)
				begin = index;
			size = index;
		}
		if (!s[++index + 1] && begin < 0)
			return (ft_strdup("\0"));
	}
	return (ft_strsub(s, begin, size - begin + 1));
}
