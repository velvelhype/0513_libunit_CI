#include <stdlib.h>
#include "libft.h"

static int	success(void)
{
	char	*str;

	str = " \t\n\v\f\r42";
	return (ft_atoi(str) == atoi(str));
}

int	ft_atoi_space_test(void)
{
	if (success())
		return (0);
	else
		return (-1);
}
