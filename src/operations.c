#include "push_swap.h"

void	swap(t_stack **stack, char *opstr)
{
	t_stack	*tmp;

	if (!(*stack)->next)
		return ;
	tmp = (*stack)->next;
	if (tmp->next)
		tmp->next->previous = *stack;
	(*stack)->previous = tmp;
	(*stack)->next = tmp->next;
	tmp->previous = NULL;
	tmp->next = *stack;
	*stack = tmp;
	ft_putendl_fd(opstr, STDOUT_FILENO);
}

void	push(t_stack **dst, t_stack **src, char *opstr)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = NULL;
	if ((*src)->next)
	{
		tmp = (*src)->next;
		tmp->previous = NULL;
	}
	if (dst && *dst)
		(*dst)->previous = *src;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
	ft_putendl_fd(opstr, STDOUT_FILENO);
}

void	rotate(t_stack **stack, char *opstr)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	(*stack)->next->previous = NULL;
	tmp = lst_last(*stack);
	tmp->next = *stack;
	(*stack)->previous = tmp;
	*stack = (*stack)->next;
	tmp->next->next = NULL;
	ft_putendl_fd(opstr, STDOUT_FILENO);
}

void	rev_rotate(t_stack **stack, char *opstr)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = lst_last(*stack);
	tmp->previous->next = NULL;
	tmp->previous = NULL;
	tmp->next = *stack;
	(*stack)->previous = tmp;
	*stack = tmp;
	ft_putendl_fd(opstr, STDOUT_FILENO);
}
