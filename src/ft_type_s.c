/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:10:38 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/17 09:12:55 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_s(const char *string)
{
	return (write(1, string, ft_strlen(string)));
}

int	ft_istype_s(char type)
{
	return (type == 's');
}
