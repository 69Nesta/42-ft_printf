/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:33:26 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/17 17:23:17 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type	ft_new_t_result(int format_count, int printed)
{
	t_type	result;

	result.format = format_count;
	result.printed = printed;
	return (result);
}
