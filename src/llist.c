/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:41:21 by gariadno          #+#    #+#             */
/*   Updated: 2021/09/20 19:51:12 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lst_last(t_stack *stack)
{
	while (stack)
	{
		if (stack->next == NULL)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	lstadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	last = lst_last(*stack);
	if (last != NULL)
	{
		last->next = new;
		new->previous = last;
	}
	else
		*stack = new;
}

t_stack	*lst_new(int num)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = num;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}

int	lst_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
