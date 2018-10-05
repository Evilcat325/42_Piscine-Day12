/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 02:54:35 by seli              #+#    #+#             */
/*   Updated: 2018/10/04 16:26:29 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H
# include <unistd.h>
# include "ft_define.h"

void	ft_putchar(int channel, char c);
void	ft_putstr(int channel, char *str);
int		ft_strlen(char *str);

#endif
