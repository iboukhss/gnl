/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:28:48 by iboukhss          #+#    #+#             */
/*   Updated: 2024/06/04 17:00:44 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	420
# endif

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
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);

#endif
