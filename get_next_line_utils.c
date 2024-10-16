/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:02:20 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/10/16 10:02:20 by lfaria-m         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(const char *str)
{
	int	i;
	i = 0;

	while (str[i])
		i ++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		i;

	result = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!result)
		return (0);
	i = 0;
	while (*s1 || *s2)
	{
		if (*s1)
		{
			result[i] = *s1;
			s1++;
			i ++;
		}
		while (!*s1 && *s2)
		{
			result[i] = *s2;
			s2++;
			i ++;
		}
	}
	result[i] = '\0';
	return (result);
}

void	*ft_memmove(void *dst, void *src, size_t len)
{
	int	i;

	if (!dst && !src && len)
		return (0);
	if (dst > src)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i --;
		}
		return (dst);
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i ++;
		}
	}
	return (dst);
}

char	*ft_memchr(char *s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	a;

	s1 = (unsigned char *)s;
	a = (unsigned char) c;
	while (n > 0)
	{
		if (*s1 == a)
			return ((void *)s1);
		s1 ++;
		n --;
	}
	return (0);
}

