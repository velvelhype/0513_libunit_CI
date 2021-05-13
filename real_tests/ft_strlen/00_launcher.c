#include <unistd.h>
#include "libunit.h"

int	basic_test(void);
int	long_string(void);
int	one_letter(void);
int	zero_length(void);
int	non_printable(void);

int	ft_strlen_launcher(void)
{
	t_unit_tests	unit_tests;
	int				result;

	write(1, "FT_STRLEN:\n", 11);
	init_tests(&unit_tests);
	load_test(&unit_tests, "Basic test         ", &basic_test);
	load_test(&unit_tests, "Long string test   ", &long_string);
	load_test(&unit_tests, "One letter test    ", &one_letter);
	load_test(&unit_tests, "Zero length test   ", &zero_length);
	load_test(&unit_tests, "Non-printable test ", &non_printable);
	result = launch_tests(&unit_tests);
	free_tests(&unit_tests);
	return (result);
}
