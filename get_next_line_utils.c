/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:28:37 by iboukhss          #+#    #+#             */
/*   Updated: 2024/06/04 11:30:48 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	unsigned char	*new;

	new = malloc(new_size * sizeof(*new));
	if (!new)
		return (NULL);
	if (!ptr)
		return (new);
	memcpy(new, ptr, old_size);
	free(ptr);
	ptr = NULL;
	return (new);
}
