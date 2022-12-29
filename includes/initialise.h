/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:31:07 by zraunio           #+#    #+#             */
/*   Updated: 2022/12/29 12:55:50 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef INITIALISE_H
# define INITIALISE_H
# include "shell.h"
# include "structs.h"

/*
** INIT
*/
void	init_shell(t_shell *shell, char **environ);
void 	init_term(void);
void	init_prompt(t_shell *shell);
# endif
