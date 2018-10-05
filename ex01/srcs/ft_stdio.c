/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 03:01:09 by seli              #+#    #+#             */
/*   Updated: 2018/10/04 19:34:32 by seli             ###   ########.fr       */
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
