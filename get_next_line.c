/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:28:20 by iboukhss          #+#    #+#             */
/*   Updated: 2024/06/04 17:12:23 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Initialization routine
 * Note: careful with double pointers
 */
static void	init_buffer(t_buffer **buf)
{
	if (!*buf)
		*buf = calloc(1, sizeof(**buf));
	if (*buf)
	{
		(*buf)->len = 0;
		(*buf)->line = NULL;
	}
}

/* Cleanup routine
 * Note: careful with double pointers
 */
static void	free_buffer(t_buffer **buf)
{
	free((*buf)->line);
	(*buf)->line = NULL;
	free(*buf);
	*buf = NULL;
}

/* Read fd into buffer
 * Note: repetitive error checking
 */
static void	read_buffer(t_buffer *buf, int fd)
{
	if (!buf->nbytes)
	{
		buf->pos = buf->data;
		buf->nbytes = read(fd, buf->pos, BUFFER_SIZE);
		buf->err |= (!buf->nbytes && !buf->line);
		buf->err |= (buf->nbytes == -1);
	}
}

/* Allocate the line
 * Note: lots of things going on, maybe refactor?
 */
static void	get_line(t_buffer *buf)
{
	char	*tmp;
	char	*nl;
	size_t	chunk_size;

	if (!buf->err)
	{
		nl = memchr(buf->pos, '\n', buf->nbytes);
		if (!nl)
			chunk_size = buf->nbytes;
		else
			chunk_size = nl - buf->pos + 1;
		tmp = ft_realloc(buf->line, buf->len, buf->len + chunk_size + 1);
		buf->err |= !tmp;
		if (buf->err)
			return ;
		buf->line = tmp;
		memcpy(buf->line + buf->len, buf->pos, chunk_size);
		buf->len += chunk_size;
		buf->line[buf->len] = '\0';
		buf->pos += chunk_size;
		buf->nbytes -= chunk_size;
	}
}

/* Main function
 * Note: careful about short-circuit evaluation
 */
char	*get_next_line(int fd)
{
	static t_buffer	*buf;

	init_buffer(&buf);
	if (!buf)
		return (NULL);
	buf->err |= (fd < 0 || BUFFER_SIZE <= 0);
	while (!buf->err)
	{
		read_buffer(buf, fd);
		if (!buf->err && !buf->nbytes)
			return (buf->line);
		get_line(buf);
		if (!buf->err && buf->line[buf->len - 1] == '\n')
			return (buf->line);
	}
	free_buffer(&buf);
	return (NULL);
}
