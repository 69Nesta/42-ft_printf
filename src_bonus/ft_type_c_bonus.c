/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:06:29 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/26 11:05:13 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_type_c(char c, const t_args *arg)
{
	(void)arg;
	return (write(1, &c, 1));
}

int	ft_istype_c(const t_args *arg)
{
	return (arg->type == 'c');
}
