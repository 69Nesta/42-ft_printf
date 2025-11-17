/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:10:38 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/17 15:08:25 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type	ft_type_s(const char *string)
{
	t_type	result;

	result = ft_new_t_result(1, 0);
	if (!string)
		result.printed = write(1, &"(null)", 6);
	else
		result.printed = write(1, string, ft_strlen(string));
	return (result);
}

int	ft_istype_s(const char *type)
{
	return (type[0] == 's');
}
