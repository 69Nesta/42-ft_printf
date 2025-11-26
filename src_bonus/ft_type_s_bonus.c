/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:10:38 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/26 11:44:36 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_type_s(const char *string, const t_args *arg)
{
	int	count;

	count = 0;
	if (!string)
		count = write(1, &"(null)", 6);
	else
		count = ft_putstr(string);
	return (count);
}

int	ft_istype_s(const t_args *arg)
{
	return (arg->type == 's');
}
