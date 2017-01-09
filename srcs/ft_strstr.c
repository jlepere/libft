/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 10:05:04 by jlepere           #+#    #+#             */
/*   Updated: 2016/09/26 17:48:39 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*ps1;
	char	*ps2;

	if (!*s2)
		return ((char*)s1);
	while (*s1)
	{
		ps1 = (char*)s1;
		ps2 = (char*)s2;
		while (*ps2 && *ps1 == *ps2)
		{
			ps1++;
			ps2++;
		}
		if (!*ps2)
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
