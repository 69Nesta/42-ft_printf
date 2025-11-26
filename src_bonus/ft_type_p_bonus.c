/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:16:05 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/26 11:40:44 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_type_p(unsigned long pointer, const t_args *arg)
{
	int	count;

	count = 0;
	if (!pointer)
		return (ft_putstr("(nil)"));
	count += write(1, &"0x", 2);
	count += ft_putnbr_base(pointer, "0123456789abcdef", 16);
	return (count);
}

int	ft_istype_p(const t_args *arg)
{
	return (arg->type == 'p');
}
