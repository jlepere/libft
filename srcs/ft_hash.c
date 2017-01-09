/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:14:48 by jlepere           #+#    #+#             */
/*   Updated: 2016/11/04 11:19:36 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_hash(const char *str)
{
	size_t	hash;
	size_t	bash;
	size_t	first;
	size_t	indice;

	indice = 0;
	hash = 0x811c9dc5;
	bash = 0x01000193;
	while (str[indice])
	{
		if (!indice)
			first = str[indice];
		hash = (hash + str[indice++]) * first % 65536;
		bash = (bash + hash) * first % 65536;
		hash ^= bash;
	}
	bash *= (first << (indice / 16)) * bash;
	return ((bash << 16) | hash);
}
