/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 21:44:52 by nohtou            #+#    #+#             */
/*   Updated: 2021/04/23 07:02:13 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	dummy_top;
	t_list	*tail;

	dummy_top.next = NULL;
	tail = &dummy_top;
	while (lst)
	{
		tail->next = ft_lstnew(f(lst->content));
		if (tail->next == NULL)
		{
			ft_lstclear(&dummy_top.next, del);
			return (NULL);
		}
		tail = tail->next;
		lst = lst->next;
	}
	return (dummy_top.next);
}
