/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:10:15 by jlepere           #+#    #+#             */
/*   Updated: 2016/11/03 23:24:14 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*str;
	char	*pstr;

	if (!f || !(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	pstr = str;
	while (*s)
		*pstr++ = (*f)(*s++);
	return (str);
}
