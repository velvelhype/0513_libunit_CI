static int	success(void)
{
	int	a;

	a = 0;
	a = 42 / a;
	return (1);
}

int	true_sigfpe(void)
{
	if (success())
		return (0);
	else
		return (-1);
}
