/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 09:56:53 by jlepere           #+#    #+#             */
/*   Updated: 2016/11/03 23:50:21 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (s && *s)
	{
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

char			**ft_strsplit(const char *s, char c)
{
	size_t	end;
	size_t	index;
	size_t	words;
	char	**data;

	words = ft_count_words(s, c);
	if (!s || !(data = ft_memalloc(sizeof(char*) * (words + 1))))
		return (NULL);
	data[words] = 0;
	index = ft_strlen(s) - 1;
	end = index + 1;
	while (words)
	{
		if (s[index] == c && s[index - 1] != c)
			end = index;
		if (s[index] != c && (s[index - 1] == c || !index))
		{
			data[--words] = ft_strsub(s, index, end - index);
			end = 0;
		}
		index--;
	}
	return (data);
}
