/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <iboukhss@student.42luxe...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:28:37 by iboukhss          #+#    #+#             */
/*   Updated: 2024/06/05 09:54:08 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	char	*s;

	s = ptr;
	while (n)
	{
		*s++ = c;
		--n;
	}
	return (ptr);
}

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	const char	*s;

	s = ptr;
	while (n)
	{
		if (*s == c)
			return ((void *)s);
		++s;
		--n;
	}
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	while (n)
	{
		*d++ = *s++;
		--n;
	}
	return (dst);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size && nmemb > (size_t)-1 / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, size);
	return (ptr);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new;

	new = malloc(new_size);
	if (!new)
		return (NULL);
	if (!ptr)
		return (new);
	ft_memcpy(new, ptr, old_size);
	free(ptr);
	return (new);
}
