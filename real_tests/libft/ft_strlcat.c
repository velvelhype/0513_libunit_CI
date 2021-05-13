/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 22:04:40 by nohtou            #+#    #+#             */
/*   Updated: 2021/04/23 06:43:01 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	dlen;
	size_t	cpy_size;

	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	if (dlen >= dstsize)
		return (dstsize + slen);
	cpy_size = dstsize - dlen - 1;
	if (cpy_size > slen)
		cpy_size = slen;
	ft_memcpy(dst + dlen, src, cpy_size);
	dst[dlen + cpy_size] = '\0';
	return (dlen + slen);
}
