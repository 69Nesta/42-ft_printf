/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:33:29 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/17 08:58:30 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr(unsigned int n, int fd);

int	ft_type_i(int n)
{
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		return (ft_putnbr(n * -1, 1) + 1);
	}
	else
		return (ft_putnbr(n, 1));	
}

int	ft_istype_i(char type)
{
	return (type == 'i' || type == 'd');
}

static int	ft_putnbr(unsigned int n, int fd)
{
	int count; 
	
	count = 0;
	if (n / 10 > 0)
		count = ft_putnbr(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
	return (count + 1);
}
