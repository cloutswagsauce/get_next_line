/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:44:42 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/10/15 13:44:41 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = (size_t)ft_strlen(src);
	dst_len = (size_t)ft_strlen(dst);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = 0;
	while (src[i] && (dst_len + i) < dstsize - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*source;

	if (!dst && !src && n)
		return (0);
	source = (char *) src;
	dest = (char *) dst;
	while (n > 0)
	{
		*dest = *source;
		dest ++;
		source ++;
		n --;
	}
	return (dst);
}

char	*ft_strchr(char *str, int c)
{
	int				i;
	unsigned char	ch;

	i = 0;
	ch = (unsigned char)c;
	if (ch == '\0')
	{
		i = ft_strlen(str);
		return ((char *)str + i);
	}
	ch = (unsigned char) c;
	while (str[i])
	{
		if (str[i] == ch)
			return ((char *)str + i);
		i ++;
	}
	return (0); 
}
int ft_strlen(char *str)
{
	int	i;
	i = 0;

	while (str[i])
		i ++;
	return (i);
}
