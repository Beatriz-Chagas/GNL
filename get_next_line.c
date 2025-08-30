/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchagas- <bchagas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 23:24:42 by bchagas-          #+#    #+#             */
/*   Updated: 2025/08/30 06:50:05 by bchagas-         ###   ########.fr       */
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
// #include <unistd.h>

// char *get_next_line(int fd);

// int main()
// {
//     int fd = open("teste.txt", O_RDONLY);  // Abre o arquivo para leitura
//     if (fd == -1)
//     {
//         perror("Erro ao abrir o arquivo");
//         return 1;
//     }

//     char *line;
//     while ((line = get_next_line(fd)) != NULL)  // Chama a função até o EOF
//     {
//         printf("Linha: %s\n", line);
//         free(line);  // Libera a memória alocada para a linha
//     }

//     close(fd);  // Fecha o arquivo
//     return 0;
// }
