#include <strings.h>
#include "libft.h"

static int	hoge(void)
{
	char	str[1024];

	memset(str, 'a', 1023);
	str[1023] = '\0';
	return (ft_strlen(str) == strlen(str));
}

int	long_string(void)
{
	if (hoge())
		return (0);
	else
		return (-1);
}
