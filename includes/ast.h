/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:47:26 by pskytta           #+#    #+#             */
/*   Updated: 2022/12/19 14:47:26 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H
# include "shell.h"

void	ast_tree(t_ast *root, t_tok *head, t_shell *shell);
//void	ast_execute(t_ast *root, t_shell *shell);
//void	ast_release(t_ast *root);

# endif
