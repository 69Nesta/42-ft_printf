/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:03:09 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/28 11:03:48 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_type_x(unsigned int hex, const t_args *arg)
{
	int	count;

	(void)arg;
	count = 0;
	count += ft_putnbr_base(hex, "0123456789abcdef", 16);
	return (count);
}

int	ft_istype_x(const t_args *arg)
{
	return (arg->type == 'x');
}
