/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 07:33:36 by jlepere           #+#    #+#             */
/*   Updated: 2016/11/04 07:41:50 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_arrdel(char **as)
{
	int	i;

	i = 0;
	while (as && as[i])
		ft_strdel(&as[i++]);
	if (as)
		free(as);
	as = NULL;
}
