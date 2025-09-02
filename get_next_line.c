/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 23:24:42 by bchagas-          #+#    #+#             */
/*   Updated: 2025/09/02 06:34:43 by bchagas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char *ft_first_line(int fd, char *line)
{
	char	*buffer;
	size_t	get_bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	get_bytes = 1;
	while (!ft_strchr(line, '\n') && get_bytes > 0)
	{
		get_bytes = read(fd, buffer, BUFFER_SIZE);
		if (get_bytes == -1)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		buffer[get_bytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*over;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	return (NULL);
	line = ft_first_line(fd, line);
}
// #include <stdio.h>
// #include <fcntl.h>

// int main(void)
// {
//     int fd;
//     char *line;
//     fd = STDIN_FILENO;
//     fd = open("teste.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Erro ao abrir o arquivo");
//         return (1);
//     }
//     // while ((line = get_next_line(fd)) != NULL)
//     // {
//     //     printf("%s\n", line);
//     //     free(line);
//     // }
// 	line = get_next_line(fd);
// 	printf("%s\n", line);
//     close(fd);
//     return (0);
// }
