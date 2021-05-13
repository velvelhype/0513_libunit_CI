/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 20:47:10 by nohtou            #+#    #+#             */
/*   Updated: 2021/04/23 07:14:20 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	cpy_size;

	if (dst == NULL || src == NULL)
		return (0);
	slen = ft_strlen(src);
	if (dstsize == 0)
		return (slen);
	cpy_size = slen;
	if (slen > dstsize - 1)
		cpy_size = dstsize - 1;
	ft_memcpy(dst, src, cpy_size);
	dst[cpy_size] = '\0';
	return (slen);
}
