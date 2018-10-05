/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 19:14:43 by seli              #+#    #+#             */
/*   Updated: 2018/10/04 21:37:06 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"

int		main(int ac, char **av)
{
	int	i;
	int	err;

	if (ac < 1)
		return (1);
	if (ac == 1)
		return (ft_repl());
	i = 1;
	while (i < ac)
	{
		err = ft_open_file(av[i]) == EXIT_ERROR ? EXIT_ERROR : err;
		i++;
	}
	return (0);
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
		return (ft_error_handle(str, dir));
	while ((result = read(fd, buf, BUF_SIZE)))
	{
		buf[result] = 0;
		ft_putstr(STDOUT_FILENO, buf);
	}
	buf[result] = 0;
	ft_putstr(STDOUT_FILENO, buf);
	if (dir > 0)
		close(dir);
	if (close(fd) < 0)
	{
		ft_putstr(STDERR_FILENO, ERROR_WHEN_CLOSE);
		return (1);
	}
	return (0);
}

int		ft_error_handle(char *str, int dir)
{
	ft_putstr(STDERR_FILENO, "cat: ");
	ft_putstr(STDERR_FILENO, str);
	ft_putstr(STDERR_FILENO, ": ");
	if (errno == ENOENT)
		ft_putstr(STDERR_FILENO, ENOENT_MSG);
	else if (errno == EACCES)
		ft_putstr(STDERR_FILENO, EACCES_MSG);
	else if (dir >= 0)
		ft_putstr(STDERR_FILENO, EISDIR_MSG);
	ft_putchar(STDERR_FILENO, '\n');
	errno = 0;
	return (1);
}

int		ft_repl(void)
{
	int		result;
	char	buf[BUF_SIZE + 1];

	while ((result = read(STDIN_FILENO, buf, BUF_SIZE)))
	{
		buf[result] = 0;
		ft_putstr(STDOUT_FILENO, buf);
	}
	buf[result] = 0;
	ft_putstr(STDOUT_FILENO, buf);
	return (0);
}
