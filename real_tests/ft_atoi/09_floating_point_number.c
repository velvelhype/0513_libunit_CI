#include <stdlib.h>
#include "libft.h"

static int	success(void)
{
	char	*str;

	str = "1234.56789";
	return (ft_atoi(str) == atoi(str));
}

int	ft_atoi_floating_point_test(void)
{
	if (success())
		return (0);
	else
		return (-1);
}
