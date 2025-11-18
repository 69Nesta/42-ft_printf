/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:53:31 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/18 08:29:21 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n / 10 > 0)
		count = ft_putnbr(n / 10);
	return (count + ft_type_c(n % 10 + '0').printed);
}
