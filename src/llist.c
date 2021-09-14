/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:41:21 by gariadno          #+#    #+#             */
/*   Updated: 2021/09/14 06:16:28 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lst_last(t_stack *stack)
{
	while(stack)
	{
		if (stack->next == NULL)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	lstadd_back(t_stack **stack, t_stack *new)
{
	t_stack *last;

	if (!stack)
		return ;
	last = lst_last(*stack);
	if (last != NULL)
		last->next = new;
	else
		*stack = new;
}

void	lstadd_front(t_stack **stack, t_stack *new)
{
	if (!new)
		return ;
	(*stack)->previous = new;
	new->next = *stack;
	*stack = new;
}

t_stack	*lst_new(int *num)
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
