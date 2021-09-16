/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:40:09 by gariadno          #+#    #+#             */
/*   Updated: 2020/01/30 19:54:55 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long int	i;
	char				*desty;
	char				*ori;

	if (src == dst)
		return (dst);
	desty = (char *)dst;
	ori = (char *)src;
	i = 0;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len--)
			desty[len] = ori[len];
	}
	return (dst);
}
