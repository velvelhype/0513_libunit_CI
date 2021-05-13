#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "libft.h"

static int	success(void)
{
	char	str[32];

	sprintf(&str[1], "%ld", LONG_MIN);
	str[1] = '9';
	str[2] = '9';
	return (ft_atoi(str) == atoi(str));
}

int	ft_atoi_underflow_test(void)
{
	if (success())
		return (0);
	else
		return (-1);
}
