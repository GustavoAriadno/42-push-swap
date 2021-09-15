/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 20:21:13 by gariadno          #+#    #+#             */
/*   Updated: 2021/09/14 22:12:15 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**fill_args(int argc, char **argv)
{
	char	**array;
	int		i;

	if (argc < 0 || !argv)
		return (NULL);
	array = malloc(sizeof(char*) * (argc + 1));
	if (!array)
		return(NULL);
	i = -1;
	while(++i < argc)
		array[i] = ft_strdup(argv[i]);
	array[i] = NULL;
	return(array);
}

char	**get_inp(int argc, char **argv)
{
	if (argc == 1)
		return(ft_split(argv[1], ' '));
	else if (argc > 1)
		return(fill_args(argc, &(argv[1])));
	return(NULL);
}
