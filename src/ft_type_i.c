/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:33:29 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/17 16:57:53 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parse_padding(const char *format, t_padding *padding);
static int	ft_print_padding(t_padding *padding, int n);

t_type	ft_type_i(int n, const char *format)
{
	t_type		result;
	t_padding	padding;

	result = ft_new_t_result(ft_parse_padding(format, &padding), 0);
	result.printed = ft_print_padding(&padding, n);
	if (n < 0)
		result.printed += ft_type_c('-').printed + ft_putnbr_u(n * -1);
	else
		result.printed += ft_putnbr_u(n);
	return (result);
}

int	ft_istype_i(const char *type)
{
	int		i;

	i = 0;
	if (type[i] == '0' || type[i] == ' ' || type[i] == '-')
		i++;
	while (ft_isdigit(type[i]) || type[i] == '+' || type[i] == '.')
		i++;
	return (type[i] == 'i' || type[i] == 'd');
}

// x : -
// x : 0
// x : .
// x : ' '
static int	ft_parse_padding(const char *format, t_padding *padding)
{	
	int	i;

	i = 0;
	padding->fill = ' ';
	padding->revers = format[i] == '-';
	if (format[i] == '-')
		i++;
	padding->plus = format[i] == '+';
	if (format[i] == '+')
		i++;
	if (format[i] == '.' || format[i] == '0')
	{
		padding->fill = '0';
		i++;
	}
	else if (format[i] == ' ')
		i++;
	padding->len = ft_atoi(format + i);
	while (ft_isdigit(format[i]))
		i++;
	return (1 + i);
}

static int	ft_print_padding(t_padding *padding, int n)
{
	int	i;
	int	print_count;
	int	print_nb_size;

	i = 0;
	(void)i;
	print_count = 0;
	print_nb_size = ft_putnbr_pre_calc(n);
	if (padding->fill == '0' && padding->plus && n >= 0)
		print_count += write(1, &"+", 1);
	while (print_count < (padding->len - print_nb_size))
	{
		print_count += write(1, &(padding->fill), 1);
	}
	if (padding->fill == ' ' && padding->plus && n >= 0)
		print_count += write(1, &"+", 1);
	return (print_count);
}
