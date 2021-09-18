/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 21:27:57 by gariadno          #+#    #+#             */
/*   Updated: 2021/09/18 20:12:55 by gariadno         ###   ########.fr       */
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

char	**fill_args(int argc, char **argv)
{
	char	**array;
	int		i;

	if (argc < 0 || !argv)
		return (NULL);
	array = malloc(sizeof(char *) * (argc + 1));
	if (!array)
		return (NULL);
	i = -1;
	while (++i < argc)
		array[i] = ft_strdup(argv[i]);
	array[i] = NULL;
	return (array);
}

char	**get_inp(int argc, char **argv)
{
	if (argc == 1)
		return (ft_split(argv[1], ' '));
	else if (argc > 1)
		return (fill_args(argc, &(argv[1])));
	return (NULL);
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
	free_lst(a);
	printf("Ok!");
	return (0);
}
