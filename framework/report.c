/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42.tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:57:28 by nohtou            #+#    #+#             */
/*   Updated: 2021/05/13 19:58:24 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "private.h"

static void	print_signal(int fd, int stat_loc)
{
	if (WTERMSIG(stat_loc) == SIGSEGV)
		ft_putstr_fd(" : [SIGV]\t\t", fd);
	else if (WTERMSIG(stat_loc) == SIGBUS)
		ft_putstr_fd(" : [BUSE]\t\t", fd);
	else if (WTERMSIG(stat_loc) == SIGALRM)
		ft_putstr_fd(" : [TIMEOUT]\t", fd);
	else if (WTERMSIG(stat_loc) == SIGFPE)
		ft_putstr_fd(" : [SIGFPE]\t\t", fd);
	else if (WTERMSIG(stat_loc) == SIGABRT)
		ft_putstr_fd(" : [SIGABRT]\t", fd);
	else
		ft_putstr_fd(" : [ERROR]\t", fd);
}

int	write_report(int fd, t_unit_tests *unit_tests, t_unit_test *test,
	int stat_loc)
{
	ft_putstr_fd("\t", fd);
	ft_putstr_fd((char *)test->test_name, fd);
	if (WIFSIGNALED(stat_loc))
		print_signal(fd, stat_loc);
	else if (WIFEXITED(stat_loc))
	{
		if (WEXITSTATUS(stat_loc) == 0)
			ft_putstr_fd(" : [OK]\t\t", fd);
		else if (WEXITSTATUS(stat_loc) == (-1 & 0xff))
			ft_putstr_fd(" : [KO]\t\t", fd);
		else
			ft_putstr_fd(" : [ERROR]\t\t", fd);
	}
	ft_putnbr_fd(unit_tests->end_clock - unit_tests->start_clock, fd);
	ft_putstr_fd(" ms\n", fd);
	return (0);
}

void	write_report_total(int fd, t_unit_tests *unit_tests)
{
	ft_putnbr_fd(unit_tests->success, fd);
	ft_putstr_fd(" / ", fd);
	ft_putnbr_fd(unit_tests->total, fd);
	ft_putstr_fd(" tests checked\n\n", fd);
}

int	open_report(t_unit_tests *unit_tests)
{
	int	fd;

	fd = open("report.log", O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		free_tests(unit_tests);
		exit(-1);
	}
	return (fd);
}
