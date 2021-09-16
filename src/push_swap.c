/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 21:27:57 by gariadno          #+#    #+#             */
/*   Updated: 2021/09/16 21:34:42 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(char **args)
{
	t_stack	*a;
	t_stack	*tmp;
	long	num;
	int		i;

	i = -1;
	a = NULL;
	while (args[++i])
	{
		num = ft_atol(args[i]);
		if (num < INT_MIN || num > INT_MAX)
			break ;
		tmp = lst_new(num);
		if (!tmp)
			break ;
		lstadd_back(&a, tmp);
	}
	if (args[i])
	{
		free_lst(a);
		free_exit(args);
	}
	free_mat(args);
	return (a);
}

int	main(int argc, char *argv[])
{
	char	**args;
	t_stack	*a;
	t_stack	*b;

	args = get_inp(--argc, argv);
	if (!args || args_are_invalid(args))
		free_exit(args);
	a = create_stack(args);
	b = NULL;
	if (!is_sorted(a))
		start_sort(&a, &b);

	// printf("1 = %d\n", a->num);
	// printf("2 = %d\n", a->next->num);
	// printf("3 = %d\n", a->next->next->num);
	free_lst(a);
	printf("Ok!");
	return (0);
}
