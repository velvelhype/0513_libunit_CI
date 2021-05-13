#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "libft.h"

static int	success(void)
{
	char	str[32];

	sprintf(str, "%ld", LONG_MAX);
	str[0] = '9';
	str[1] = '9';
	return (ft_atoi(str) == atoi(str));
}

int	ft_atoi_overflow_test(void)
{
	if (success())
		return (0);
	else
		return (-1);
}
