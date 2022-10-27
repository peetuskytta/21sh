/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_endl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:24:27 by pskytta           #+#    #+#             */
/*   Updated: 2022/10/13 09:12:59 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_endl(int nb)
{
	ft_putnbr_fd(nb, STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
}
