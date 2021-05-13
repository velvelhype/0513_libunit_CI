#include <strings.h>
#include "libft.h"

int	zero_length(void)
{
	char	*str;

	str = "";
	if (ft_strlen(str) == strlen(str))
		return (0);
	else
		return (-1);
}
