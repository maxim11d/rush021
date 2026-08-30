/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dico.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsaulni <arsaulni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 11:09:11 by arsaulni          #+#    #+#             */
/*   Updated: 2026/08/30 13:56:43 by arsaulni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE 4096

int	get_file_size(char *filepath)
{
	int		fd;
	int		ret;
	int		size;
	char	tmp[BUF_SIZE];

	fd = open((const char *)filepath, O_RDONLY);
	if (fd < 0)
		return (-1);
	size = 0;
	ret = read(fd, tmp, BUF_SIZE);
	while (ret > 0)
	{
		size += ret;
		ret = read(fd, tmp, BUF_SIZE);
	}
	close(fd);
	if (ret < 0)
		return (-1);
	return (size);
}

static int	fill_buffer(int fd, char *buffer)
{
	int	ret;
	int	total;

	total = 0;
	ret = read(fd, buffer + total, BUF_SIZE);
	while (ret > 0)
	{
		total += ret;
		ret = read(fd, buffer + total, BUF_SIZE);
	}
	if (ret < 0)
		return (-1);
	buffer[total] = '\0';
	return (total);
}

char	*read_full_file(char *filepath)
{
	int		fd;
	int		size;
	char	*buffer;

	size = get_file_size(filepath);
	if (size < 0)
		return (0);
	buffer = malloc(sizeof(*buffer) * (size + 1));
	if (!buffer)
		return (0);
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		free(buffer);
		return (0);
	}
	if (fill_buffer(fd, buffer) < 0)
	{
		close(fd);
		free(buffer);
		return (0);
	}
	close(fd);
	return (buffer);
}
