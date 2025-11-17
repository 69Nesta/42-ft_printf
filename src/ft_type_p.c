/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:16:05 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/17 17:23:36 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type	ft_type_p(unsigned long pointer)
{
	t_type	result;

	result = ft_new_t_result(1, 0);
	if (!pointer)
		return (ft_type_s("(nil)"));
	result.printed += write(1, &"0x", 2);
	result.printed += ft_putnbr_base_u(pointer, "0123456789abcdef", 16);
	return (result);
}

int	ft_istype_p(const char *type)
{
	return (type[0] == 'p');
}
