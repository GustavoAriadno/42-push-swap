/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 21:27:57 by gariadno          #+#    #+#             */
/*   Updated: 2021/09/14 06:15:50 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stacks(char **args)
{
	t_stack	*a;
	int	*tmp;

	a = lst_new();

}

int		main(int argc, char *argv[])
{
	char **args;

	args = get_inp(--argc, argv);
	if (!args || check_if_args_are_invalid(args))
		free_exit(args);

	// create_stacks();

	// printf("%d\n", ft_strisnum(*args));
	while(args && *args)
		ft_putendl_fd(*args++, 1);
	// free_array(&args);
	printf("Ok!");
	return (0);
}
