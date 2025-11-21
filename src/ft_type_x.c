/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:03:09 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/21 18:07:00 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type	ft_type_x(unsigned int hex, const char *format)
{
	t_type	result;

	result = ft_new_t_result(1, 0);
	result.printed += ft_putnbr_base(hex, "0123456789abcdef", 16);
	return (result);
}

int	ft_istype_x(const char *type)
{
	return (type[0] == 'x');
}
