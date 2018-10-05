/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 19:14:43 by seli              #+#    #+#             */
/*   Updated: 2018/10/04 23:10:06 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"

int		main(int ac, char **av)
{
	int		i;
	int		dir;
	char	*offset;

	if (ac <= 3)
		return (1);
	i = 1;
	if (av[1][0] == '-' && av[1][1] == 'c' && av[1][2] == '\0')
		i++;
	offset = i == 1 ? &av[1][2] : av[2];
	while (++i < ac)
	{
		dir = open(av[i], O_RDONLY | O_DIRECTORY);
		if (dir >= 0)
		{
			ft_print_file_name(av[i]);
			close(dir);
		}
		else
			ft_print_tail(ft_size(av[i]), ft_offset(offset), av[i]);
	}
	return (0);
}
