#include <stdlib.h>
#include <limits.h>
#include "libft.h"

static int	success(void)
{
	char	*str;

	str = "0001234";
	return (ft_atoi(str) == atoi(str));
}

int	ft_atoi_000_head_test(void)
{
	if (success())
		return (0);
	else
		return (-1);
}
