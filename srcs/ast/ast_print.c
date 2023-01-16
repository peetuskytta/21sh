#include "shell.h"

/*DELETE BEFORE SUBMIT*/
void ast_print(t_ast *tree)
{
	if (tree == NULL)
		return ;
	if (tree->type == COMMAND || tree->type == REDIR)
	{
		int ct = 0;
		while (tree->data.args[ct])
		{
			if (ct == 0)
				ft_putstr("CMD->  ");
			else
				ft_putstr("ARG->    ");
			ft_printf("%s\n", tree->data.args[ct++]);
		}
		if (tree->type == REDIR)
		{
			int i = 0;
			if (i == 0)
				ft_putstr("  RED->  |  ");
			while (tree->data.redir[i].file)
				ft_printf("%s  |  ", tree->data.redir[i++].file);
		}
	}
	ast_print(tree->left);
	if (tree->type == PIPE)
		ast_print(tree->right);
}
