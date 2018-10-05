/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 22:13:36 by seli              #+#    #+#             */
/*   Updated: 2018/10/04 23:07:15 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H
# include <fcntl.h>
# include <errno.h>
# include "ft_define.h"
# include "ft_stdio.h"

void	ft_print_file_name(char *str);
int		ft_print_tail(int size, int offset, char *str);
int		ft_size(char *str);
int		ft_offset(char *str);
int		ft_error_handle(char *str);

#endif
