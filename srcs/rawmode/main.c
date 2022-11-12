#include "../../includes/shell.h"
#include <stdio.h>

int	main(void)
{
	t_shell	shell;

	ft_memset(&shell, 0, sizeof(t_shell));
	if (enable_rawmode(&shell) == 0)
		ft_putendl_fd("Error with tcgetattr", STDERR_FILENO);
	else
	{
		write(STDOUT_FILENO, "\x1b[2J", 4);
		write(STDOUT_FILENO, "\x1b[H", 3);
		init_window(&shell.window);
		while (1)
			keypress(&shell);
	}
	kill_mode("exit", &shell);
	return (0);
}
