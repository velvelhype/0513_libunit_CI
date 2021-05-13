/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 23:44:43 by nohtou            #+#    #+#             */
/*   Updated: 2020/07/01 23:53:24 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*applied;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	applied = malloc(len + 1);
	if (applied == NULL)
		return (NULL);
	applied[len] = '\0';
	while (len--)
		applied[len] = f(len, s[len]);
	return (applied);
}
