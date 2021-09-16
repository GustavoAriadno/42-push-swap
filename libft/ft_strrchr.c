/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 10:14:25 by gariadno          #+#    #+#             */
/*   Updated: 2020/01/24 19:20:19 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	int				j;
	char			*str;

	i = 0;
	j = -1;
	str = (char *)s;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			j = i;
		i++;
	}
	if (c == 0)
		return (&str[i]);
	if (j >= 0)
		return (&str[j]);
	return (0);
}
