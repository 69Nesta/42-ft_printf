/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpetit <rpetit@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:33:26 by rpetit            #+#    #+#             */
/*   Updated: 2025/11/28 11:03:53 by rpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *str)
{
	if (!str)
		return (0);
	return (write(1, str, ft_strlen(str)));
}

int	ft_ischarset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i] && set[i] != c)
		i++;
	return (c == set[i]);
}

int	ft_is_num(const char c)
{
	return (c >= '0' && c <= '9');
}
