/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:53:31 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/01 11:29:05 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putnbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n / 10 > 0)
		count = ft_putnbr(n / 10);
	return (count + ft_putchar(n % 10 + '0'));
}

int	ft_putnbr_len(unsigned int n, const t_args *arg)
{
	int	count;

	count = 0;
	if (arg->space_sign || arg->show_sign)
		count++;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

