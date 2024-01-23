/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:34:45 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/22 13:48:01 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

void	get_buffer(char **buffer)
{
	if (*buffer == NULL)
	{
		*buffer = (char *)malloc(1);
		if (*buffer == NULL)
			return ;
		**(buffer) = '\0';
	}
}

void	*update_buffer(char *buffer, char *tmp_buff, int num_bytes)
{
	char	*new_buffer;

	new_buffer = NULL;
	get_buffer(&buffer);
	if (num_bytes > 0)
	{
		new_buffer = ft_strjoin(buffer, tmp_buff);
		if (new_buffer == NULL)
			return (NULL);
		free(buffer);
	}
	if (num_bytes == 0)
		new_buffer = buffer;
	return (new_buffer);
}

char	*get_line_from_buffer(char	**buffer, int num_bytes)
{
	char	*line;
	int		pos;
	char	*aux;
	size_t	len;

	line = NULL;
	len = ft_strlen(*buffer);
	pos = ft_strchr(*buffer, "\n\r");
	if (pos >= 0)
	{
		line = ft_substr(*buffer, 0, pos + 1);
		aux = *buffer;
		*buffer = ft_substr(*buffer, pos + 1, len);
		free (aux);
		return (line);
	}
	if (num_bytes == 0)
	{
		line = ft_substr(*buffer, 0, len);
		free(*buffer);
		*buffer = NULL;
	}
	return (line);
}

char	*read_line(char **buffer, int fd)
{
	char	*chr_buffer;
	char	*line;
	int		num_bytes;

	chr_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (chr_buffer == NULL)
		return (NULL);
	line = NULL;
	while (line == NULL)
	{
		num_bytes = read(fd, chr_buffer, BUFFER_SIZE);
		if (num_bytes < 0)
			return (free_ptr(chr_buffer));
		else
		{
			chr_buffer[num_bytes] = '\0';
			*buffer = update_buffer(*buffer, chr_buffer, num_bytes);
			if (*buffer == NULL)
				return (free_ptr(chr_buffer));
		}
		line = get_line_from_buffer(buffer, num_bytes);
	}
	free(chr_buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char			*buffer;
	char				*line;

	get_buffer(&buffer);
	if (buffer == NULL)
		return (NULL);
	if (fd < 0 && BUFFER_SIZE <= 0)
	{
		free (buffer);
		buffer = NULL;
		return (NULL);
	}
	line = read_line(&buffer, fd);
	if (line != NULL && ft_strlen(line) == 0)
	{
		free (line);
		line = NULL;
	}
	if (line == NULL)
	{
		free (buffer);
		buffer = NULL;
		return (NULL);
	}
	return (line);
}

/*
int	main(int argc, char **argv)
{
	int fd;
	char *line;
	
	argc++;
	line = argv[0];
	fd = 1;
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("\t<%s>\n",line);
		free (line);
	}
	printf("LINE ES NULL");
	
}
*/