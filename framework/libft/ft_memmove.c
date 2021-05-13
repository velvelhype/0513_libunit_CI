/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 18:01:41 by nohtou            #+#    #+#             */
/*   Updated: 2021/04/23 06:52:53 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	int					re;

	if (!dst && !src && len)
		return (dst);
	re = dst > src;
	if (re)
	{
		d = dst + len -1;
		s = src + len -1;
	}
	else
	{
		d = dst;
		s = src;
	}
	while (len--)
	{
		if (re)
			*d-- = *s--;
		else
			*d++ = *s++;
	}
	return (dst);
}
