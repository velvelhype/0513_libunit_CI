#include <unistd.h>
#include "libunit.h"

int	true_ok(void);
int	true_ko(void);
int	true_segv(void);
int	true_bus_error(void);
int	true_timeout(void);
int	true_sigfpe(void);
int	true_sigabrt(void);

int	true_function_launcher(void)
{
	t_unit_tests	unit_tests;
	int				result;

	write(1, "TRUE_FUNCTION:\n", 15);
	init_tests(&unit_tests);
	load_test(&unit_tests,
		"True OK test                        ", &true_ok);
	load_test(&unit_tests,
		"True KO test                        ", &true_ko);
	load_test(&unit_tests,
		"True segmentation fault test        ", &true_segv);
	load_test(&unit_tests,
		"True bus error test                 ", &true_bus_error);
	load_test(&unit_tests,
		"True timeout test                   ", &true_timeout);
	load_test(&unit_tests,
		"True Floating Point Exception test  ", &true_sigfpe);
	load_test(&unit_tests,
		"True abrt test                      ", &true_sigabrt);
	result = launch_tests(&unit_tests);
	free_tests(&unit_tests);
	return (result);
}
