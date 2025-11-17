/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_xx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:06:38 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/17 17:24:06 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type	ft_type_xx(unsigned int hex, const char *format)
{
	t_type	result;

	result = ft_new_t_result(1, 0);
	if (format[0] == '#')
	{
		result.printed = write(1, &"0X", 2);
		result.format++;
	}
	result.printed += ft_putnbr_base_u(hex, "0123456789ABCDEF", 16);
	return (result);
}

int	ft_istype_xx(const char *type)
{
	return (type[0] == 'X' || (type[0] == '#' && type[1] == 'X'));
}
