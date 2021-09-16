/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:25:24 by gariadno          #+#    #+#             */
/*   Updated: 2020/01/27 12:31:19 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(void *s, int c, unsigned long int n)
{
	unsigned long int	i;
	char				*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == c)
		{
			return (&str[i]);
		}
		i++;
	}
	return (0);
}
