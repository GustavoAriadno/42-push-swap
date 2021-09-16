/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 20:42:16 by gariadno          #+#    #+#             */
/*   Updated: 2021/09/13 20:42:45 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisnum(char *num)
{
	if (!num)
		return (0);
	if (*num == '-' && num[1])
		num++;
	while (ft_isdigit(*num))
		num++;
	return (!(*num));
}
