#include "../../inlcudes/shell.h"
#include <stdio.h>

int	main(void)
{
	char	c;
	t_shell	shell;

	ft_memset(&shell, 0, sizeof(t_shell));
	ft_memset(shell.window, 0, sizeof(t_win));
	if (enable_rawmode() == 0)
		ft_putendl_fd("Error with tcgetattr", STDERR_FILENO);
	else
	{
		init_window(shell.window);
		while (1)
			keypress();
	}
	return (0);
}
