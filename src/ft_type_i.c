/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:33:29 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/18 08:29:23 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type	ft_type_i(int n)
{
	t_type		result;

	result = ft_new_t_result(1, 0);
	if (n < 0)
		result.printed += ft_type_c('-').printed + ft_putnbr(n * -1);
	else
		result.printed += ft_putnbr(n);
	return (result);
}

int	ft_istype_i(const char *type)
{
	return (type[0] == 'i' || type[0] == 'd');
}
