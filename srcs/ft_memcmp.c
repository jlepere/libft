/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 09:58:51 by jlepere           #+#    #+#             */
/*   Updated: 2016/09/21 14:33:54 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				res;
	unsigned char	*ps1;
	unsigned char	*ps2;

	res = 0;
	ps1 = (unsigned char*)s1;
	ps2 = (unsigned char*)s2;
	while (n-- && !res)
		res = (*ps1++) - (*ps2++);
	return (res);
}
