/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:31:12 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/17 12:48:55 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long n, const char *base)
{
	int	count;

	if (n < 0)
	{
		count = write(1, &"-", 1);
		count += ft_putnbr_base_u(n * -1, base, ft_strlen(base));
	}
	else
		count = ft_putnbr_base_u(n, base, ft_strlen(base));
	return (count);
}

int	ft_putnbr_base_u(unsigned long n, const char *base, int base_len)
{
	int	count;

	count = 0;
	if (n / base_len > 0)
		count = ft_putnbr_base_u(n / base_len, base, base_len);
	count += write(1, &(base[n % base_len]), 1);
	return (count);
}
