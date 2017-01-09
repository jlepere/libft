/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 10:02:55 by jlepere           #+#    #+#             */
/*   Updated: 2016/09/21 14:40:08 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	char	*str;
	char	*pstr;

	if (!(str = ft_strnew(ft_strlen(s1))))
		return (NULL);
	pstr = str;
	while (*s1)
		*pstr++ = *s1++;
	return (str);
}
