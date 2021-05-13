/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:18:37 by nohtou            #+#    #+#             */
/*   Updated: 2021/04/23 06:29:11 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>
#include <errno.h>
#include "libft.h"

static int	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ');
}

static int	overflow(long n, char digit)
{
	if (n > LONG_MAX / 10)
	{
		errno = ERANGE;
		return (1);
	}
	if (n == LONG_MAX / 10)
	{
		if (n * 10 > LONG_MAX - (digit - '0'))
		{
			errno = ERANGE;
			return (1);
		}
	}
	return (0);
}

static int	underflow(long n, char digit)
{
	if (n > -(LONG_MIN / 10))
	{
		errno = ERANGE;
		return (1);
	}
	if (n == -(LONG_MIN / 10))
	{
		if (n * 10 > LONG_MIN - (digit - '0'))
		{
			errno = ERANGE;
			return (1);
		}
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	long	ret;
	int		conv;
	int		sign;

	while (is_space(*str))
		str++;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	ret = 0;
	conv = 0;
	while (ft_isdigit(*str))
	{
		conv = 1;
		if ((sign == -1) && underflow(ret, *str))
			return ((int)LONG_MIN);
		if ((sign == 1) && overflow(ret, *str))
			return ((int)LONG_MAX);
		ret = ret * 10 + (*str++ - '0');
	}
	if (!conv)
		errno = EINVAL;
	return (sign * ret);
}
