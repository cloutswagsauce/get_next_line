/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:08:52 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/10/18 09:04:26 by lfaria-m         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>   

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		s_len;
	int		i;

	s_len = ft_strlen(s1);
	result = malloc(sizeof(char) * s_len + 1);
	if (!result)
		return (0);
	i = 0;
	while (i < s_len && s1[i])
	{
		result[i] = s1[i];
		i ++;
	}
	result[i] = '\0';
	return (result);
}
char *get_line_from_stash(char *stash)
{
	char	*newline_pos;
	char	*line;
	size_t	line_len;

	newline_pos = ft_memchr(stash, '\n', ft_strlen(stash));
	line_len = newline_pos - stash + 1;
	line = (char *) malloc(sizeof(char) * (line_len + 1));
	ft_memmove(line, stash, line_len);
	line[line_len] = '\0';
	return (line);
}
char *update_stash(char *stash)
{
	char	*newline_pos;
	char	*new_stash;

	newline_pos = ft_memchr(stash, '\n', ft_strlen(stash));
	if (!newline_pos)
	{
		free(stash);
		return (0);
	}
	new_stash = ft_strdup(newline_pos + 1);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	char		buffer[1025];
	static char	*stash;
	char		*line;
	ssize_t		bytes_read;

	bytes_read = 1;
	//if (!stash)
		//stash = ft_strdup("");
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		stash = malloc(1025);
		stash = ft_strjoin(stash, buffer);
		if (ft_memchr(stash, '\n', ft_strlen(stash)))
			break;
	}
	if (bytes_read == 0 || bytes_read == -1)
		return (0);
	if (!stash || !*stash)
			return (0);
	line = get_line_from_stash(stash);
	stash = update_stash(stash);
	return (line);
	
}

int main()
{
    int fd = open("readmebish.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error reading filename");
        exit(1);
    }

    char *line;
    // Keep calling get_next_line() until it returns NULL
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);  // Free the line after printing
    }

    close(fd);
    return 0;
}