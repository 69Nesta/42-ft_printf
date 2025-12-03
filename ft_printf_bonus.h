/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:09:06 by rpetit            #+#    #+#             */
/*   Updated: 2025/12/02 19:25:44 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);

typedef char	t_bool;

typedef struct s_type
{
	int	format;
	int	printed;
}	t_type;

typedef struct s_atol
{
	long	value;
	int		len;
}	t_atol;

typedef struct s_args
{
	char	type;
	int		length;
	int		width;
	int		precision;
	t_bool	has_precision;
	// flags
	t_bool	left_align;
	t_bool	zero_pad;
	t_bool	show_sign;
	t_bool	space_sign;
	t_bool	alternate_form;

	int		arg_len;
}	t_args;

// others
t_atol	ft_atol(const char *nptr);
int		ft_atoi(const char *nptr);
int		ft_putnbr(unsigned int n);
int		ft_putnbr_len(unsigned int n, const t_args *arg);
int		ft_putnbr_base(unsigned long n, const char *base, int base_len);
int		ft_putnbr_base_len(unsigned long n, int base_len);

// utils
int		ft_strlen(const char *str);
int		ft_putchar(char c);
int		ft_putstr(const char *str);
int		ft_ischarset(char c, char *set);
int		ft_is_num(const char c);
int		ft_max(int a, int b);
void	ft_swrite(int *count, int write_value);

// format args
t_args	ft_format_arg(const char *token);
int		ft_right_align(const t_args *arg, const char fill, int w, int is_null);
int		ft_left_align(const t_args *arg, const char fill, int printed_w);
int		ft_middle_zero(const t_args *arg, const char fill, int printed_w);

// printf types
int		ft_type_i(int n, const t_args *arg);
int		ft_istype_i(const t_args *arg);

int		ft_type_c(char c, const t_args *arg);
int		ft_istype_c(const t_args *arg);

int		ft_type_s(const char *string, const t_args *arg);
int		ft_istype_s(const t_args *arg);

int		ft_type_p(unsigned long pointer, const t_args *arg);
int		ft_istype_p(const t_args *arg);

int		ft_type_u(unsigned int n, const t_args *arg);
int		ft_istype_u(const t_args *arg);

int		ft_type_x(unsigned int hex, const t_args *arg);
int		ft_istype_x(const t_args *arg);

int		ft_type_xx(unsigned int hex, const t_args *arg);
int		ft_istype_xx(const t_args *arg);

int		ft_type_mod(const t_args *arg);
int		ft_istype_mod(const t_args *arg);

#endif