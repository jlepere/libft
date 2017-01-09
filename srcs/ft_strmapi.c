/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:26:32 by jlepere           #+#    #+#             */
/*   Updated: 2016/11/04 06:28:02 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	if (!f || !(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = 0;
	while (*s)
	{
		str[i] = (*f)(i, *s++);
		i++;
	}
	return (str);
}
