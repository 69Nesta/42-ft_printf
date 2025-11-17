/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:33:29 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/17 13:04:32 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_i(int n)
{
	if (n < 0)
		return (ft_type_c('-') + ft_putnbr_u(n * -1));
	else
		return (ft_putnbr_u(n));
}

int	ft_istype_i(const char *type)
{
	return (type[0] == 'i' || type[0] == 'd');
}
