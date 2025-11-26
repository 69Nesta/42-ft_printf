/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_xx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:06:38 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/26 10:29:27 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type	ft_type_xx(unsigned int hex)
{
	t_type	result;

	result = ft_new_t_result(1, 0);
	result.printed += ft_putnbr_base(hex, "0123456789ABCDEF", 16);
	return (result);
}

int	ft_istype_xx(const char *type)
{
	return (type[0] == 'X');
}
