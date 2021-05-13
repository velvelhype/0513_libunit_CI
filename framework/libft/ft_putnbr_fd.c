/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 14:21:31 by nohtou            #+#    #+#             */
/*   Updated: 2020/07/03 15:24:19 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	disp_digit(int fd, unsigned int nbr)
{
	char	digit;

	if (nbr < 10)
		digit = '0' + nbr;
	else
	{
		disp_digit(fd, nbr / 10);
		digit = '0' + (nbr % 10);
	}
	write(fd, &digit, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	unbr;

	if (n < 0)
	{
		unbr = -(n + 1);
		unbr++;
		write(fd, "-", 1);
	}
	else
		unbr = n;
	disp_digit(fd, unbr);
}
