/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:16:05 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/17 13:04:44 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_p(unsigned long pointer)
{
	int	printed_char;

	printed_char = 0;
	if (!pointer)
		return (ft_type_s("(nil)"));
	printed_char += write(1, &"0x", 2);
	printed_char += ft_putnbr_base_u(pointer, "0123456789abcdef", 16);
	return (printed_char);
}

int	ft_istype_p(const char *type)
{
	return (type[0] == 'p');
}
