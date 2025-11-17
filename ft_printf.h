/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:09:06 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/17 15:11:10 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);

typedef struct s_type {
	int format;
	int	printed;
}	t_type;

t_type	ft_new_t_result(int format_count, int printed);

int		ft_putnbr_u(unsigned int n);
int		ft_putnbr_base(long n, const char *base);
int		ft_putnbr_base_u(unsigned long n, const char *base, int base_len);

t_type	ft_type_i(int n);
int		ft_istype_i(const char *type);

t_type	ft_type_c(char c);
int		ft_istype_c(const char *type);

t_type	ft_type_s(const char *string);
int		ft_istype_s(const char *type);

t_type	ft_type_p(unsigned long pointer);
int		ft_istype_p(const char *type);

t_type	ft_type_u(int n);
int		ft_istype_u(const char *type);

t_type	ft_type_x(unsigned int hex, const char *format);
int		ft_istype_x(const char *type);

t_type	ft_type_xx(unsigned int hex, const char *format);
int		ft_istype_xx(const char *type);

t_type	ft_type_mod(const char *format);
int		ft_istype_mod(const char *type);

#endif