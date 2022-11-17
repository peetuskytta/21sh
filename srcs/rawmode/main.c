#include "../../includes/shell.h"
#include <stdio.h>

int	main(void)
{
	t_shell	shell;

	ft_memset(&shell, 0, sizeof(t_shell));
	// ft_memset(shell.window, 0, sizeof(t_win));
	if (enable_rawmode(&shell) == 0)
		ft_putendl_fd("Error with tcgetattr", STDERR_FILENO);
	else
	{
		// init_window(shell.window);
		while (1)
			keypress(&shell);
	}
	kill_mode("exit", &shell);
	return (0);
}
