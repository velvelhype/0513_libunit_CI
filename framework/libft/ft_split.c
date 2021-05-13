/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 00:01:20 by nohtou            #+#    #+#             */
/*   Updated: 2021/04/23 07:18:08 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_delimiter(char c, char delimiter)
{
	return (c == delimiter || c == '\0');
}

static int	get_substr_count(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str++)
	{
		if (is_delimiter(*str, c) && !is_delimiter(*(str - 1), c))
			count++;
	}
	return (count);
}

static char	*cut_substr(const char **str_ptr, char c)
{
	char	*start;
	char	*sub_str;

	while (is_delimiter(**str_ptr, c))
		(*str_ptr)++;
	start = (char *)*str_ptr;
	while (!is_delimiter(**str_ptr, c))
		(*str_ptr)++;
	sub_str = malloc(*str_ptr - start + 1);
	if (sub_str == NULL)
		return (NULL);
	ft_memcpy(sub_str, start, *str_ptr - start);
	sub_str[*str_ptr - start] = '\0';
	return (sub_str);
}

static void	free_list(char **str_list, int size)
{
	while (size--)
		free(str_list[size]);
	free(str_list);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**str_list;
	int		i;

	if (s == NULL)
		return (NULL);
	count = get_substr_count(s, c);
	str_list = malloc(sizeof(char *) * (count + 1));
	if (str_list == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		str_list[i] = cut_substr(&s, c);
		if (str_list[i] == NULL)
		{
			free_list(str_list, i);
			return (NULL);
		}
		i++;
	}
	str_list[i] = NULL;
	return (str_list);
}
