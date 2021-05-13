#include <strings.h>
#include "libft.h"

int	non_printable(void)
{
	char	*str;

	str = "\a42\bTokyo\n";
	if (ft_strlen(str) == strlen(str))
		return (0);
	else
		return (-1);
}
