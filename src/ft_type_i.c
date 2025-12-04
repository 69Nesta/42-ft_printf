/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:33:29 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/04 14:02:02 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_right_align_i(const t_args *arg, int n, int nlen);
static int	ft_middle_align_i(const t_args *arg, int n, int nlen);

int	ft_type_i(int n, const t_args *arg)
{
	int	count;
	int	len;

	count = 0;
	len = 0;
	if (n < 0)
		len = ft_putnbr_len(n * -1, arg) + 1;
	else if (!(n == 0 && arg->has_precision && arg->precision == 0))
		len = ft_putnbr_len(n, arg);
	ft_swrite(&count, ft_right_align_i(arg, n, len));
	ft_swrite(&count, ft_middle_align_i(arg, n, len));
	if (n < 0)
		ft_swrite(&count, ft_putnbr(n * -1));
	else if (!(n == 0 && arg->has_precision && arg->precision == 0))
		ft_swrite(&count, ft_putnbr(n));
	ft_swrite(&count, ft_left_align(arg, ' ', count));
	return (count);
}

int	ft_istype_i(const t_args *arg)
{
	return (arg->type == 'i' || arg->type == 'd');
}

static int	ft_right_align_i(const t_args *arg, int n, int nlen)
{
	int	i;
	int	printed;

	i = 0;
	printed = 0;
	if (arg->left_align)
		return (printed);
	if ((n < 0 || arg->show_sign || arg->space_sign)
		&& (arg->zero_pad && !arg->has_precision))
		ft_swrite(&printed, ft_putchar('+' * (n >= 0 && arg->show_sign)
				+ '-' * (n < 0)
				+ ' ' * (n >= 0 && arg->space_sign)));
	while ((ft_max(nlen, arg->precision + (n < 0))) + i < arg->width)
	{
		ft_swrite(&printed, ft_putchar(
				' ' * (!arg->zero_pad || arg->has_precision)
				+ '0' * (arg->zero_pad && !arg->has_precision)));
		i++;
	}
	return (printed);
}

static int	ft_middle_align_i(const t_args *arg, int n, int nlen)
{
	int	i;
	int	printed;

	i = 0;
	printed = 0;
	if ((n < 0 || arg->show_sign || arg->space_sign)
		&& (!arg->zero_pad || arg->has_precision))
		ft_swrite(&printed, ft_putchar('+' * (n >= 0 && arg->show_sign)
				+ '-' * (n < 0)
				+ ' ' * (n >= 0 && arg->space_sign)));
	if (!(arg->zero_pad || arg->precision > (nlen - (n < 0))))
		return (printed);
	while (nlen + i - (n < 0) < arg->precision)
	{
		ft_swrite(&printed, ft_putchar('0'));
		i++;
	}
	return (printed);
}
