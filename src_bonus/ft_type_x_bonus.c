/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:03:09 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/02 19:50:39 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int ft_right_align_x(const t_args *arg, int nlen);
static int ft_middle_align_x(const t_args *arg, int nlen);

int	ft_type_x(unsigned int hex, const t_args *arg)
{
	int	count;
	int	len;

	count = 0;
	len = ft_putnbr_base_len(hex, 16);
	if (arg->alternate_form)
		len += 2;
	ft_swrite(&count, ft_right_align_x(arg, len));
	// count += ft_right_align_x(arg, len);
	ft_swrite(&count, ft_middle_align_x(arg, len));
	// count += ft_middle_align_x(arg, len);
	ft_swrite(&count, ft_putnbr_base(hex, "0123456789abcdef", 16));
	// count += ft_putnbr_base(hex, "0123456789abcdef", 16);
	ft_swrite(&count, ft_left_align(arg, ' ', count));
	// count += ft_left_align(arg, ' ', count);
	return (count);
}

int	ft_istype_x(const t_args *arg)
{
	return (arg->type == 'x');
}

static int ft_right_align_x(const t_args *arg, int nlen)
{
	int	i;
	int	printed;

	i = 0;
	printed = 0;
	if (arg->left_align)
		return (printed);
	if (arg->alternate_form && arg->zero_pad)
		ft_swrite(&printed, ft_putstr("0x"));
	while ((ft_max(nlen, arg->precision)) + i < arg->width)
	{
		ft_swrite(&printed, ft_putchar(' ' * (!arg->zero_pad || arg->precision) + '0' * (arg->zero_pad && !arg->precision)));
		i++;
	}
	return (printed);
}

static int ft_middle_align_x(const t_args *arg, int nlen)
{
	int	i;
	int	printed;

	i = 0;
	printed = 0;
	if (arg->alternate_form && !arg->zero_pad)
		ft_swrite(&printed, ft_putstr("0x"));
	if (!(arg->zero_pad || arg->precision > (nlen)))
		return (printed);
	while (nlen + i < arg->precision)
	{
		ft_swrite(&printed, ft_putchar('0'));
		i++;
	}
	return (printed);
}
