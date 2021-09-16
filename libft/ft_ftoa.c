#include "libft.h"

static long double	ft_round(long double n)
{
	long double		right;
	long unsigned	left;

	left = (unsigned)n;
	right = n - (double)left;
	if (right > 0.5)
		n += 0.5;
	else if (right == 0.5)
	{
		if ((left % 2))
			n += 0.5;
	}
	return ((unsigned long)n);
}

static char	*ft_left(char *str, size_t len, unsigned long right, long double n)
{
	char	*tmp;
	char	*r;
	char	*i;

	tmp = NULL;
	r = NULL;
	i = NULL;
	r = ft_strjoin(str, ".");
	free(str);
	while (len--)
	{
		n *= 10;
		right = n;
		right %= 10;
		i = ft_itoa(right);
		free(tmp);
		tmp = ft_strjoin(r, i);
		free(r);
		r = ft_strdup(tmp);
		free(i);
	}
	free(tmp);
	return (r);
}

char	*ft_ftoa(long double n, size_t len)
{
	char			*str;
	unsigned long	left;
	unsigned long	right;

	right = 0;
	if (!len)
		n = ft_round(n);
	left = (long unsigned)n;
	n = n - (long double)left;
	str = ft_itoa(left);
	if (len)
		str = ft_left(str, len, right, n);
	return (str);
}
