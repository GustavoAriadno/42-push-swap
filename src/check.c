#include "push_swap.h"

int	check_if_there_are_duplicates(char **args)
{
	int	i;
	int	j;
	int	cmplen;

	i = -1;
	while (args[++i])
	{
		j = i;
		cmplen = ft_strlen(args[i]);
		while (args[++j])
			if (ft_strncmp(args[i], args[j], cmplen + ft_strlen(args[j])) == 0)
				return (1);
	}
	return (0);
}

int	check_if_args_are_invalid(char **args)
{
	int i;

	i = -1;
	while (args[++i])
		if (!ft_strisnum(args[i]) ||
			ft_strlen(args[i]) > 11 ||
			(ft_strlen(args[i]) == 11 && args[i][0] != '-'))
			return (1);
	return (check_if_there_are_duplicates(args));
}
