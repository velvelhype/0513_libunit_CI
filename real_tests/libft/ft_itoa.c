/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 19:31:03 by nohtou            #+#    #+#             */
/*   Updated: 2020/07/06 03:12:47 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	set_digit(char **str_ptr, unsigned int n)
{
	if (n < 10)
		**str_ptr = '0' + n;
	else
	{
		set_digit(str_ptr, n / 10);
		**str_ptr = '0' + (n % 10);
	}
	(*str_ptr)++;
}

char	*ft_itoa(int a)
{
	unsigned int	n;
	char			buff[64];
	char			*p;

	p = buff;
	if (a < 0)
	{
		n = -(a + 1);
		n++;
		*p = '-';
		p++;
	}
	else
		n = a;
	set_digit(&p, n);
	*p = '\0';
	return (ft_strdup(buff));
}
