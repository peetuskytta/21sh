/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 08:10:24 by pskytta           #+#    #+#             */
/*   Updated: 2022/12/19 10:38:51 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	token_list_free(t_tok *list)
{
	t_tok	*temp;
	t_tok	*store;

	temp = list;
	while (temp != NULL)
	{
		store = temp->next;
		ft_strdel(&temp->str);
		ft_memdel((void *)&(temp));
		temp = store;
	}
	list = NULL;
}
