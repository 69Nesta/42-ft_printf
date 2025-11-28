/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_i_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:33:29 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/28 16:42:35 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_type_i(int n, const t_args *arg)
{
	int	count;
	int len;

	count = 0;
	if (n < 0)
		len = ft_putnbr_len(n * -1) + 1;
	else
		len = ft_putnbr_len(n);
	count += ft_right_align(arg, '0' * arg->zero_pad + ' ' * !arg->zero_pad, len, n > 0);
	if (n < 0)
	{
		count += ft_putchar('-');
		count += ft_middle_zero(arg, '0', len);
		count += ft_putnbr(n * -1);
	}
	else
		count += ft_putnbr(n);
	count += ft_left_align(arg, ' ', len);
	return (count);
}

int	ft_istype_i(const t_args *arg)
{
	return (arg->type == 'i' || arg->type == 'd');
}
