/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42lausanne.ch>    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:45:41 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/10/21 19:47:24 by lfaria-m         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i ++;
	}
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*result;
	size_t	len;

	len = ft_strlen(s1);
	result = (char *) malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	ft_memmove(result, s1, len + 1);
	return (result);
}

void	*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst && !src)
		return (0);
	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d += len;
		s += len;
		while (len--)
			*--d = *--s;
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = malloc(sizeof(char) * ((s1_len + s2_len) + 1));
	if (!result)
		return (0);
	ft_memmove(result, s1, s1_len);
	j = 0;
	while (j < s2_len)
	{
		result[s1_len + j] = s2[j];
		j++;
	}
	result[s1_len + j] = '\0';
	return (result);
}

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	a;

	s1 = (unsigned char *)s;
	a = (unsigned char) c;
	while (n --)
	{
		if (*s1 == a)
			return ((void *)s1);
		s1 ++;
	}
	return (0);
}
