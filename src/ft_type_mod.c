/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:24:26 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/17 17:24:26 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type	ft_type_mod(const char *format)
{
	t_type	result;
	int		i;

	i = 0;
	result = ft_type_c('%');
	while (format[i] == ' ')
		i++;
	result.format += i;
	return (result);
}

int	ft_istype_mod(const char *type)
{
	int	i;

	i = 0;
	while (type[i] == ' ')
		i++;
	return (type[i] == '%');
}
