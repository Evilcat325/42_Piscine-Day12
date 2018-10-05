/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 15:59:01 by seli              #+#    #+#             */
/*   Updated: 2018/10/04 19:11:58 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"

int		main(int ac, char **av)
{
	if (ac == 1)
		ft_putstr(STDERR, ERROR_MISSING_FILE_NAME);
	else if (ac > 2)
		ft_putstr(STDERR, ERROR_TOO_MANY_ARGUMENTS);
	else
		return (ft_open_file(av[1]));
}

int		ft_open_file(char *str)
{
	int		fd;
	int		dir;
	int		result;
	char	buf[BUF_SIZE + 1];

	dir = open(str, O_RDONLY | O_DIRECTORY);
	fd = open(str, O_RDONLY);
	if (fd < 0 || dir >= 0)
		return (1);
	while ((result = read(fd, buf, BUF_SIZE)))
	{
		buf[result] = 0;
		ft_putstr(STDOUT, buf);
	}
	buf[result] = 0;
	ft_putstr(STDOUT, buf);
	if (dir > 0)
		close(dir);
	if (close(fd) < 0)
	{
		ft_putstr(STDERR, ERROR_WHEN_CLOSE);
		return (1);
	}
	return (0);
}
