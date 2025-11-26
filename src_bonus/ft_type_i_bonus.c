/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_i_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:33:29 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/26 11:19:59 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_type_i(int n, const t_args *arg)
{
	int	count;

	count = 0;
	if (n < 0)
		count += ft_putchar('-') + ft_putnbr(n * -1);
	else
		count += ft_putnbr(n);
	return (count);
}

int	ft_istype_i(const t_args *arg)
{
	return (arg->type == 'i' || arg->type == 'd');
}
