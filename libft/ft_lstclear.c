/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:17:54 by gariadno          #+#    #+#             */
/*   Updated: 2020/01/31 13:04:10 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*swap;

	if (lst == NULL)
		return ;
	swap = (*lst)->next;
	while ((*lst))
	{
		swap = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = swap;
	}
}
