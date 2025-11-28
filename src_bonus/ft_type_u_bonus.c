/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:33:29 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/28 11:03:45 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_type_u(int n, const t_args *arg)
{
	(void)arg;
	return (ft_putnbr(n));
}

int	ft_istype_u(const t_args *arg)
{
	return (arg->type == 'u');
}
