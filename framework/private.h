/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nohtou <nohtou@student.42.tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 18:16:52 by nohtou            #+#    #+#             */
/*   Updated: 2021/05/13 19:57:06 by nohtou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_H
# define PRIVATE_H

# include "libunit.h"

# define TRUE	1
# define FALSE	0
# define OK		1
# define ERROR	1

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define RESET	"\033[0m"

t_unit_test	*new_test(const char *test_name, int (*test_func)(void));
void		add_test(t_unit_tests *list, t_unit_test *test);
char		*ft_strdup(const char *str);
int			write_report(int fd, t_unit_tests *unit_tests, t_unit_test *test,
				int stat_loc);
void		write_report_total(int fd, t_unit_tests *unit_tests);
int			open_report(t_unit_tests *unit_tests);

#endif
