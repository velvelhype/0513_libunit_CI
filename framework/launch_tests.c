/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42.tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 18:15:24 by nohtou            #+#    #+#             */
/*   Updated: 2021/05/13 13:33:48 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "libft.h"
#include "private.h"

void	print_result(t_unit_tests *unit_tests, t_unit_test *test, int stat_loc)
{
	ft_putstr_fd("\t", 1);
	ft_putstr_fd((char *)test->test_name, 1);
	if (WIFSIGNALED(stat_loc))
	{
		if (WTERMSIG(stat_loc) == SIGSEGV)
			ft_putstr_fd(" : \033[31m[SIGV]\033[0m\n", 1);
		else if (WTERMSIG(stat_loc) == SIGBUS)
			ft_putstr_fd(" : \033[31m[BUSE]\033[0m\n", 1);
		else
			ft_putstr_fd(" : \033[31m[ERROR]\033[0m\n", 1);
	}
	else if (WIFEXITED(stat_loc))
	{
		if (WEXITSTATUS(stat_loc) == 0)
		{
			ft_putstr_fd(" : \033[32m[OK]\033[0m\n", 1);
			unit_tests->success++;
		}
		else if (WEXITSTATUS(stat_loc) == (-1 & 0xff))
			ft_putstr_fd(" : \033[31m[KO]\033[0m\n", 1);
		else
			ft_putstr_fd(" : \033[31m[ERROR]\033[0m\n", 1);
	}
	unit_tests->total++;
}

void	launch_func(t_unit_tests *unit_tests, int (*func)(void))
{
	pid_t	pid;
	int		result;

	pid = fork();
	if (pid == -1)
		exit(ERROR);
	if (pid == 0)
	{
		result = func();
		free_tests(unit_tests);
		exit(result);
	}
}

void	print_toral(t_unit_tests *unit_tests)
{
	ft_putnbr_fd(unit_tests->success, 1);
	ft_putstr_fd(" / ", 1);
	ft_putnbr_fd(unit_tests->total, 1);
	ft_putstr_fd(" tests checked\n\n", 1);
}

int	launch_tests(t_unit_tests *unit_tests)
{
	t_unit_test	*test;
	int			stat_loc;

	test = unit_tests->head;
	while (test)
	{
		launch_func(unit_tests, test->test_func);
		wait(&stat_loc);
		print_result(unit_tests, test, stat_loc);
		test = test->next;
	}
	print_toral(unit_tests);
	if (unit_tests->success == unit_tests->total)
		return (0);
	else
		return (-1);
}
