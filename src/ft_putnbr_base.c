/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:31:12 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/18 08:28:52 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long n, const char *base, int base_len)
{
	int	count;

	count = 0;
	if (n / base_len > 0)
		count = ft_putnbr_base(n / base_len, base, base_len);
	count += write(1, &(base[n % base_len]), 1);
	return (count);
}
