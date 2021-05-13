#include <strings.h>
#include "libft.h"

static int	hoge(void)
{
	char	*str;

	str = "a";
	return (ft_strlen(str) == strlen(str));
}

int	one_letter(void)
{
	if (hoge())
		return (0);
	else
		return (-1);
}
