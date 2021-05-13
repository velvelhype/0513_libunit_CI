/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42.tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 18:14:54 by nohtou            #+#    #+#             */
/*   Updated: 2021/05/10 17:01:55 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "private.h"

int	load_test(t_unit_tests *unit_tests, const char *test_name,
		int (*test_func)(void))
{
	t_unit_test	*test;

	test = new_test(test_name, test_func);
	if (test == NULL)
		return (ERROR);
	add_test(unit_tests, test);
	return (OK);
}
