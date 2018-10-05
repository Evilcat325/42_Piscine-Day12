/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 16:02:05 by seli              #+#    #+#             */
/*   Updated: 2018/10/04 21:35:14 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAIN_H
# define FT_MAIN_H
# include <fcntl.h>
# include <errno.h>
# include "ft_stdio.h"
# include "ft_define.h"

int		main(int ac, char **av);
int		ft_open_file(char *str);
int		ft_error_handle(char *str, int dir);
int		ft_repl(void);

#endif
