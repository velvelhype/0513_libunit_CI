#include <stdlib.h>

static int	success(void)
{
	char	*ptr;

	ptr = malloc(42);
	free(ptr);
	free(ptr);
	return (1);
}

int	true_sigabrt(void)
{
	if (success())
		return (0);
	else
		return (-1);
}
