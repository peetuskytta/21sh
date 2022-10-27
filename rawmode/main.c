#include "../../inlcudes/shell.h"
#include <stdio.h>

int	main(void)
{
	char	c;
	t_shell	shell;

	ft_memset(&shell, 0, sizeof(t_shell));
	enable_rawmode();
	while (1)
		keypress();
	return (0);
}