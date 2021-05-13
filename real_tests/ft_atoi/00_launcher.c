#include <unistd.h>
#include "libunit.h"

int	ft_atoi_basic_test(void);
int	ft_atoi_minus_test(void);
int	ft_atoi_plus_test(void);
int	ft_atoi_space_test(void);
int	ft_atoi_space_minus_test(void);
int	ft_atoi_space_plus_test(void);
int	ft_atoi_plus_minus_test(void);
int	ft_atoi_void_string_test(void);
int	ft_atoi_floating_point_test(void);
int	ft_atoi_digit_tail_test(void);
int	ft_atoi_int_max_test(void);
int	ft_atoi_int_mini_test(void);
int	ft_atoi_overflow_test(void);
int	ft_atoi_underflow_test(void);
int	ft_atoi_zero_test(void);
int	ft_atoi_000_head_test(void);

int	ft_atoi_launcher(void)
{
	t_unit_tests	unit_tests;
	int				result;

	write(1, "FT_ATOI:\n", 9);
	init_tests(&unit_tests);
	load_test(&unit_tests,
		"Basic test                   ", &ft_atoi_basic_test);
	load_test(&unit_tests,
		"Minus test                   ", &ft_atoi_minus_test);
	load_test(&unit_tests,
		"Plus test                    ", &ft_atoi_plus_test);
	load_test(&unit_tests,
		"Space test                   ", &ft_atoi_space_test);
	load_test(&unit_tests,
		"Space test                   ", &ft_atoi_space_test);
	load_test(&unit_tests,
		"Space minus test             ", &ft_atoi_space_minus_test);
	load_test(&unit_tests,
		"Space plus test              ", &ft_atoi_space_plus_test);
	load_test(&unit_tests,
		"Plus minus test              ", &ft_atoi_plus_minus_test);
	load_test(&unit_tests,
		"Void string test             ", &ft_atoi_void_string_test);
	load_test(&unit_tests,
		"Floating point number test   ", &ft_atoi_floating_point_test);
	load_test(&unit_tests,
		"Non digit tail test          ", &ft_atoi_digit_tail_test);
	load_test(&unit_tests,
		"Int max test                 ", &ft_atoi_int_max_test);
	load_test(&unit_tests,
		"Int mini test                ", &ft_atoi_int_mini_test);
	load_test(&unit_tests,
		"Overflow test                ", &ft_atoi_overflow_test);
	load_test(&unit_tests,
		"Underflow test               ", &ft_atoi_underflow_test);
	load_test(&unit_tests,
		"Zero test                    ", &ft_atoi_zero_test);
	load_test(&unit_tests,
		"000 head test                ", &ft_atoi_000_head_test);
	result = launch_tests(&unit_tests);
	free_tests(&unit_tests);
	return (result);
}
