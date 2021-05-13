/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 23:01:32 by nohtou            #+#    #+#             */
/*   Updated: 2021/04/23 07:15:42 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	same_head(const char *s1, const char *s2, size_t rem)
{
	while (*s2)
	{
		if (!rem)
			return (0);
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
		rem--;
	}
	return (1);
}

const char	*find_initial(const char *str, char c, size_t *len)
{
	while (*str && *len)
	{
		if (*str == c)
			return (str);
		str++;
		(*len)--;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*initial;

	if (!*needle)
		return ((char *)haystack);
	if (!*haystack)
		return (NULL);
	initial = find_initial(haystack, *needle, &len);
	if (initial == NULL)
		return (NULL);
	if (same_head(initial, needle, len))
		return ((char *)initial);
	return (NULL);
}
