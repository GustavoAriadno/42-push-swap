/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:25:05 by gariadno          #+#    #+#             */
/*   Updated: 2020/01/31 15:52:42 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*ori;
	char	*desty;

	if (!dst && !src)
		return (NULL);
	i = 0;
	desty = (char *)dst;
	ori = (char *)src;
	while (i < n)
	{
		desty[i] = ori[i];
		i++;
	}
	return (desty);
}
