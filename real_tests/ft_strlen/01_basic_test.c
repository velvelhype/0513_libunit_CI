#include <strings.h>
#include "libft.h"

int	basic_test(void)
{
	char	*str;

	str = "42Tokyo";
	if (ft_strlen(str) == strlen(str))
		return (0);
	else
		return (-1);
}
