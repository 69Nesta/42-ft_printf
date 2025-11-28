/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_mod_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:24:26 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/28 11:03:22 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_type_mod(const t_args *arg)
{
	(void)arg;
	return (ft_putchar('%'));
}

int	ft_istype_mod(const t_args *arg)
{
	return (arg->type == '%');
}
