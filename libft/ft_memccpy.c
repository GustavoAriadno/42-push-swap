/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:33:12 by gariadno          #+#    #+#             */
/*   Updated: 2020/02/11 14:25:08 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*desty;
	unsigned char	*ori;

	desty = (unsigned char *)dst;
	ori = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		desty[i] = ori[i];
		if (ori[i] == (unsigned char)c)
			return (&dst[i + 1]);
		i++;
	}
	return (0);
}
