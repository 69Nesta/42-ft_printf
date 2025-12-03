/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:16:05 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/02 20:09:48 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int ft_right_align_p(const t_args *arg, int nlen);
static int ft_middle_align_p(const t_args *arg, int nlen);

int	ft_type_p(unsigned long pointer, const t_args *arg)
{
	int	count;
	int len;

	count = 0;
	if (!pointer)
		len = 5;
	else
		len = ft_putnbr_base_len(pointer, 16) + 2;
	if (pointer && arg->show_sign)
		len++;
	ft_swrite(&count, ft_right_align(arg, ' ', len, pointer == 0));
	// count += ft_right_align(arg, ' ', len, pointer == 0);
	if (!pointer)
		ft_swrite(&count, ft_putstr("(nil)"));
		// count += ft_putstr("(nil)");
	else
	{
		if (arg->show_sign)
			ft_swrite(&count, ft_putchar('+'));
			// count += ft_putchar('+');
		else if (arg->space_sign)
			ft_swrite(&count, ft_putchar(' '));
			// count += ft_putchar(' ');
		ft_swrite(&count, write(1, &"0x", 2));
		// count += write(1, &"0x", 2);
		ft_swrite(&count, ft_middle_zero(arg, '0', len));
		// count += ft_middle_zero(arg, '0', len);
		ft_swrite(&count, ft_putnbr_base(pointer, "0123456789abcdef", 16));
		// count += ft_putnbr_base(pointer, "0123456789abcdef", 16);
	}
	ft_swrite(&count, ft_left_align(arg, ' ', len));
	// count += ft_left_align(arg, ' ', len);
	return (count);
}

int	ft_istype_p(const t_args *arg)
{
	return (arg->type == 'p');
}

static int ft_right_align_p(const t_args *arg, int nlen)
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
		ft_swrite(&printed, ft_putchar(' ' * (!arg->zero_pad || arg->has_precision) + '0' * (arg->zero_pad && !arg->has_precision)));
		i++;
	}
	return (printed);
}

static int ft_middle_align_p(const t_args *arg, int nlen)
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
