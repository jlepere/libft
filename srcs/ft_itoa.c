/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 09:45:09 by jlepere           #+#    #+#             */
/*   Updated: 2016/09/26 23:53:18 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*str;
	size_t	nb;
	size_t	size;

	size = ft_intlen(n);
	if (!(str = ft_strnew(size)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	nb = n;
	if (n < 0)
		nb *= -1;
	str[0] = '-';
	size--;
	while (nb > 0)
	{
		str[size--] = nb % 10 + 48;
		nb /= 10;
	}
	if (n == 0)
		str[0] = 48;
	return (str);
}
