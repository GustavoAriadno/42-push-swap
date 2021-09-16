/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:29:06 by gariadno          #+#    #+#             */
/*   Updated: 2021/05/31 15:35:02 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_len(unsigned int x)
{
	int		len;

	len = 0;
	while (x > 9)
	{
		len++;
		x = x / 10;
	}
	return (len);
}

static void	check_neg(int *n, int *len, unsigned int *nb, int *neg)
{
	if (*n < 0)
	{
		++(*len);
		++(*neg);
		*nb = *n * -1;
	}
}

char	*ft_itoa(int n)
{
	int				len;
	unsigned int	nb;
	char			*str;
	int				neg;

	len = 1;
	neg = 0;
	nb = n;
	check_neg(&n, &len, &nb, &neg);
	len = len + find_len(nb);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	if (neg == 1)
		str[0] = '-';
	str[len] = '\0';
	while (--len >= neg)
	{
		str[len] = nb % 10 + 48;
		nb /= 10;
	}
	return (str);
}
