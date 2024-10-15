/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:17:02 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/10/15 11:16:12 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>   // For exit()

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*result;
	ssize_t	bytes_read;
	int	i;

	i = 0;

	buffer = (char *) malloc(10);
	result = (char *) malloc(999);
	if (!buffer)
		return (0);
	bytes_read = read(fd, buffer, 9);
	
	buffer[bytes_read] = '\0';
	while (buffer[i])
		i ++;
	
	


	return buffer + i;



	
}

int main()
{
    int fd = open("readmebish.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error reading filename");
		exit(1);
	}
	printf("%s", get_next_line(fd));



    return 0;
}