/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 22:12:45 by seli              #+#    #+#             */
/*   Updated: 2018/10/04 23:19:45 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_print_file_name(char *str)
{
	ft_putstr(STDOUT_FILENO, "==>");
	ft_putstr(STDOUT_FILENO, str);
	ft_putstr(STDOUT_FILENO, "<==\n");
}

int		ft_print_tail(int size, int offset, char *str)
{
	int		fd;
	int		result;
	char	buf[BUF_SIZE + 1];

	errno = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0 || size < 0 || offset < 0)
		return (fd < 0 ? ft_error_handle(str) : -1);
	ft_print_file_name(str);
	if (offset < size)
	{
		while ((result = read(fd, buf, BUF_SIZE)))
			buf[result] = 0;
		lseek(fd, -offset, SEEK_END);
	}
	while ((result = read(fd, buf, BUF_SIZE)))
	{
		buf[result] = 0;
		ft_putstr(STDOUT_FILENO, buf);
	}
	buf[result] = 0;
	ft_putstr(STDOUT_FILENO, buf);
	if (close(fd) < 0)
	{
		ft_putstr(STDERR_FILENO, ERROR_WHEN_CLOSE);
		return (-1);
	}
	return (result);
}

int		ft_size(char *str)
{
	int		fd;
	int		size;
	int		result;
	char	buf[BUF_SIZE + 1];

	fd = open(str, O_RDONLY);
	size = 0;
	if (fd < 0)
		return (-1);
	while ((result = read(fd, buf, BUF_SIZE)))
		size += result;
	size += result;
	if (close(fd) < 0)
	{
		ft_putstr(STDERR_FILENO, ERROR_WHEN_CLOSE);
		return (-1);
	}
	return (size);
}

int		ft_offset(char *str)
{
	int	offset;
	int	error;

	error = 0;
	offset = ft_atoi(str, &error);
	if (error)
	{
		ft_putstr(STDERR_FILENO, "tail: illegal offset -- ");
		ft_putstr(STDERR_FILENO, str);
		ft_putchar(STDERR_FILENO, '\n');
		return (-1);
	}
	return (offset > 0 ? offset : -offset);
}

int		ft_error_handle(char *str)
{
	ft_putstr(STDERR_FILENO, "tail: ");
	ft_putstr(STDERR_FILENO, str);
	ft_putstr(STDERR_FILENO, ": ");
	if (errno == ENOENT)
		ft_putstr(STDERR_FILENO, ENOENT_MSG);
	else if (errno == EACCES)
		ft_putstr(STDERR_FILENO, EACCES_MSG);
	else
		ft_putstr(STDERR_FILENO, "Error");
	ft_putchar(STDERR_FILENO, '\n');
	return (-1);
}
