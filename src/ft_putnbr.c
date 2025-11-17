/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:53:31 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/17 16:48:49 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int n)
{
	int	count;

	count = 0;
	if (n / 10 > 0)
		count = ft_putnbr_u(n / 10);
	return (count + ft_type_c(n % 10 + '0').printed);
}

int	ft_putnbr_pre_calc(int nb)
{
	int				i;
	unsigned int	n;

	i = 0;
	n = nb;
	if (nb < 0)
	{
		n *= -1;
		i++;
	}
	while (n / 10 > 0 && ++i)
		n = n / 10;
	return (i);
}
