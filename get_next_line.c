/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:28:20 by iboukhss          #+#    #+#             */
/*   Updated: 2024/06/04 13:15:34 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_buffer	*buf;
	char			*line = NULL;
	size_t			len = 0;
	char			*nl;
	size_t			chunk_size;

	// sanity check, freeing buf is always fine
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	// happens only on the first call
	if (!buf)
	{
		buf = calloc(1, sizeof(*buf));
		if (!buf)
			return (NULL);
	}
	while (true)
	{
		// all bytes were consumed
		if (!buf->nbytes)
		{
			buf->nbytes = read(fd, buf->data, BUFFER_SIZE);
			if (buf->nbytes == -1)
			{
				free(line);
				free(buf);
				buf = NULL;
				return (NULL);
			}
			else if (buf->nbytes == 0)
			{
				if (!line)
				{
					free(buf);
					buf = NULL;
					return (NULL);
				}
				else
				{
					return (line);
				}
			}
			buf->pos = buf->data;
		}
		// look for newline
		nl = memchr(buf->pos, '\n', buf->nbytes);
		if (!nl)
			chunk_size = buf->nbytes;
		else
			chunk_size = nl - buf->pos + 1;
		// create the line
		char *newline = ft_realloc(line, len, len + chunk_size + 1);
		if (!newline)
		{
			free(line);
			free(buf);
			buf = NULL;
			return (NULL);
		}
		line = newline;
		memcpy(line + len, buf->pos, chunk_size);
		len += chunk_size;
		line[len] = '\0';
		// update positions before continuing
		buf->pos += chunk_size;
		buf->nbytes -= chunk_size;
		if (nl)
			return (line);
		// keep going
	}
}
