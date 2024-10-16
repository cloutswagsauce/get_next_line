/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:01:36 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/10/16 10:02:15 by lfaria-m         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

 #ifndef GET_NEXT_LINE_H
 # define GET_NEXT_LINE_H
 # define BUFFER_SIZE 10

 #include <stdlib.h>
 #include <unistd.h>
 
 char	*get_next_line(int fd);
 int	ft_strlen(const char *str);
 char	*ft_strjoin(char *s1, char *s2);
 void	*ft_memmove(void*dst, void *src, size_t len);
 char	*ft_memchr(char *s, int c, size_t n);


 #endif