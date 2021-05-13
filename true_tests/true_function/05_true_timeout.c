static int	success(void)
{
	while (1)
		;
	return (1);
}

int	true_timeout(void)
{
	if (success())
		return (0);
	else
		return (-1);
}
