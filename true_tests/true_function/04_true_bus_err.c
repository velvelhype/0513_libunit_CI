static int	success(void)
{
	char	*ptr;

	ptr = "42Tokyo";
	ptr[0] = 'a';
	return (1);
}

int	true_bus_error(void)
{
	if (success())
		return (0);
	else
		return (-1);
}
