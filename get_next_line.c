/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 23:24:42 by bchagas-          #+#    #+#             */
/*   Updated: 2025/08/30 07:09:47 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = (NULL);
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	if (bytes_read <= 0)
		return (NULL);
	line = malloc(bytes_read + 1);
	if (!line)
		return (NULL);
	while (i < bytes_read)
	{
		if (buffer[i] == '\n')
			line[j] = '\0';
		line[j] = buffer[i];
		i++;
		j++;
	}
	line[j] = '\0';
	return (line);
}
// #include <stdio.h>
// #include <fcntl.h>

// int main(void)
// {
//     int fd;
//     char *line;

//     fd = open("teste.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Erro ao abrir o arquivo");
//         return (1);
//     }
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s\n", line);
//         free(line);
//     }
//     close(fd);
//     return (0);
// }
