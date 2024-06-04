/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:28:48 by iboukhss          #+#    #+#             */
/*   Updated: 2024/06/04 17:42:08 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	420
# endif

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_buffer
{
	// buffer
	char	data[BUFFER_SIZE];
	char	*pos;
	ssize_t	nbytes;
	// line
	char	*line;
	size_t	len;
	// sticky error flag
	bool	err;
}	t_buffer;

char	*get_next_line(int fd);

void	*ft_memset(void *ptr, int c, size_t n);
void	*ft_memchr(const void *ptr, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);

#endif
