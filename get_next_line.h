/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:00:38 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/10/22 10:23:04 by lfaria-m         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif



size_t	ft_strlen(char *str);
char	*ft_strdup(char *s1);
void	*ft_memmove(void *dst, void *src, size_t len);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memchr(void *s, int c, size_t n);
char	*get_next_line(int fd);

#endif