/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 03:01:09 by seli              #+#    #+#             */
/*   Updated: 2018/10/04 22:17:45 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

void	ft_putchar(int channel, char c)
{
	write(channel, &c, 1);
}

void	ft_putstr(int channel, char *str)
{
	write(channel, str, ft_strlen(str));
}

int		ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

long	ft_atoi(char *str, int *error)
{
	long	result;
	long	prev_result;
	int		sign;

	sign = 1;
	result = 0;
	while (ft_isspace(str))
		str++;
	if (*str == '+' || *str == '-')
		sign = *str++ == '-' ? -1 : 1;
	while ('0' <= *str && *str <= '9')
	{
		prev_result = result;
		result = result * 10 + (*str - '0') * sign;
		if (result / 10 != prev_result)
			return (sign == 1 ? -1 : 0);
		str++;
	}
	if (*str)
		*error = 1;
	return (result);
}

int		ft_isspace(char *str)
{
	int result;

	result = FALSE;
	if (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		result = TRUE;
	return (result);
}
