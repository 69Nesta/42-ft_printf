/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:33:29 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/17 15:01:08 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type	ft_type_i(int n)
{
	t_type	result;

	result = ft_new_t_result(1, 0);
	if (n < 0)
		result.printed = ft_type_c('-').printed + ft_putnbr_u(n * -1);
	else
		result.printed = ft_putnbr_u(n);
	return (result);
}

int	ft_istype_i(const char *type)
{
	return (type[0] == 'i' || type[0] == 'd');
}
