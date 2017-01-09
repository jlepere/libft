/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 09:38:25 by jlepere           #+#    #+#             */
/*   Updated: 2016/09/21 09:15:18 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*pdst;
	unsigned char	*psrc;

	pdst = (unsigned char*)dst;
	psrc = (unsigned char*)src;
	if (psrc <= pdst)
	{
		pdst += len - 1;
		psrc += len - 1;
		while (len--)
			*pdst-- = *psrc--;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
