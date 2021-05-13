/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42.tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 18:16:08 by nohtou            #+#    #+#             */
/*   Updated: 2021/05/10 18:09:41 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "private.h"

t_unit_test	*new_test(const char *test_name, int (*test_func)(void))
{
	t_unit_test	*test;

	test = malloc(sizeof(t_unit_test));
	if (test == NULL)
		return (NULL);
	test->test_name = ft_strdup(test_name);
	if (test->test_name == NULL)
	{
		free(test);
		return (NULL);
	}
	test->test_func = test_func;
	test->next = NULL;
	return (test);
}

void	init_tests(t_unit_tests *list)
{
	list->head = NULL;
	list->tail = NULL;
	list->success = 0;
	list->total = 0;
}

void	add_test(t_unit_tests *list, t_unit_test *test)
{
	if (list->head == NULL)
	{
		list->head = test;
		list->tail = test;
	}
	else
	{
		list->tail->next = test;
		list->tail = test;
	}
}

void	free_tests(t_unit_tests *list)
{
	t_unit_test	*test;
	t_unit_test	*tmp;

	test = list->head;
	while (test)
	{
		tmp = test->next;
		free(test);
		test = tmp;
	}
	init_tests(list);
}
