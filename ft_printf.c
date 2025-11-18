/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:10:20 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/18 08:23:42 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_processing(const char *format, va_list ap);
static t_type	ft_type_selector(const char *type, va_list ap);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		printed_char_count;

	if (!format)
		return (-1);
	va_start(ap, format);
	printed_char_count = ft_processing(format, ap);
	va_end(ap);
	return (printed_char_count);
}

static int	ft_processing(const char *format, va_list ap)
{
	int		i;
	int		start_current;
	int		total_printed;
	t_type	format_result;

	i = 0;
	total_printed = 0;
	while (format[i])
	{
		start_current = i;
		while (format[i] && format[i] != '%')
			i++;
		if (i > start_current && format[start_current])
			total_printed
				+= write(1, format + start_current, i - start_current);
		if (format[i] == '%' && format[i + 1])
		{
			format_result = ft_type_selector(format + ++i, ap);
			total_printed += format_result.printed;
			i += format_result.format;
		}
	}
	return (total_printed);
}

static t_type	ft_type_selector(const char *type, va_list ap)
{
	t_type	t;

	t = ft_new_t_result(1, 0);
	if (ft_istype_c(type))
		return (ft_type_c((char)va_arg(ap, int)));
	else if (ft_istype_s(type))
		return (ft_type_s(va_arg(ap, char *)));
	else if (ft_istype_p(type))
		return (ft_type_p(va_arg(ap, unsigned long)));
	else if (ft_istype_i(type))
		return (ft_type_i(va_arg(ap, int)));
	else if (ft_istype_i(type))
		return (ft_type_i(va_arg(ap, int)));
	else if (ft_istype_u(type))
		return (ft_type_u(va_arg(ap, unsigned int)));
	else if (ft_istype_x(type))
		return (ft_type_x(va_arg(ap, unsigned int), type));
	else if (ft_istype_xx(type))
		return (ft_type_xx(va_arg(ap, unsigned int), type));
	else if (ft_istype_mod(type))
		return (ft_type_mod(type));
	return (t);
}
