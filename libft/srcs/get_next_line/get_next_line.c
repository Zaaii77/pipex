/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:50:34 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/07 07:26:13 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/get_next_line.h"

static int	check_gnl(char **buf, int *b_read, int fd)
{
	if (read(fd, 0, 0) < 0)
		return (free(*buf), *buf = NULL, 0);
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= MAXINT)
		return (free(*buf), *buf = NULL, 0);
	if (!*buf)
	{
		*buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!*buf)
			return (-2);
		*b_read = read(fd, *buf, BUFFER_SIZE);
		if (*b_read <= 0)
			return (free(*buf), *buf = NULL, 0);
		(*buf)[*b_read] = '\0';
		return (1);
	}
	*b_read = strlen_gnl(*buf);
	return (1);
}

static char	*strdup_gnl(char *buf, ssize_t j)
{
	char	*n_buf;
	size_t	len;

	len = 0;
	if (!buf || !strlen_gnl(buf))
		return (free(buf), buf = NULL, NULL);
	while (buf[j + len])
		len++;
	if (len == 0)
		return (free(buf), buf = NULL, NULL);
	n_buf = (char *)malloc(sizeof(char) * (len + 1));
	if (!n_buf)
		return (free(buf), buf = NULL, NULL);
	len = 0;
	while (buf[j])
	{
		n_buf[len] = buf[j];
		j++;
		len++;
	}
	n_buf[len] = '\0';
	return (free(buf), buf = NULL, n_buf);
}

char	*strjoin_gnl(char *line, char **buf)
{
	ssize_t	i;
	ssize_t	j;
	size_t	len;
	char	*n_line;

	if (!*buf || !line)
		return (free(line), line = NULL, NULL);
	j = -1;
	i = -1;
	n_line = NULL;
	len = strlen_gnl(line) + strline_gnl(*buf);
	n_line = (char *)malloc(sizeof(char) * (len + 1));
	if (!n_line)
		return (free(line), line = NULL, NULL);
	while (line[++i])
		n_line[i] = line[i];
	while ((*buf)[++j] && (*buf)[j] != '\n')
		n_line[i++] = (*buf)[j];
	if ((*buf)[j] == '\n')
		n_line[i++] = (*buf)[j++];
	n_line[i] = '\0';
	*buf = strdup_gnl(*buf, j);
	return (free(line), line = NULL, n_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf = NULL;
	int			b_read;

	if (check_gnl(&buf, &b_read, fd) <= 0)
		return (NULL);
	line = (char *)malloc(sizeof(char));
	if (!line)
		return (free(buf), buf = NULL, NULL);
	line[0] = '\0';
	while (b_read > 0)
	{
		line = strjoin_gnl(line, &buf);
		if (!line)
			return (free(buf), buf = NULL, NULL);
		if (isline_gnl(line))
			return (line);
		if (!strlen_gnl(buf))
			if (check_gnl(&buf, &b_read, fd) == -2)
				return (free(line), line = NULL, NULL);
		if (line && !strlen_gnl(buf))
			return (free(buf), buf = NULL, line);
	}
	return (NULL);
}
