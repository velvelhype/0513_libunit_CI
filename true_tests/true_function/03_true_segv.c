#include <stdio.h>

static int	success(void)
{
	int	*ptr;
	int	a;

	ptr = NULL;
	a = *ptr;
	return (1);
}

int	true_segv(void)
{
	if (success())
		return (0);
	else
		return (-1);
}
