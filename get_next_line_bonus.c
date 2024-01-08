/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:41:44 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/08 21:25:15 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "get_next_line_bonus.h"

/*
Function to init the buffer
*/
t_buffer	*bonus_init_buffer(t_buffer *buffer_list, int fd)
{
	t_buffer	*new_buffer;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer_list == NULL)
	{
		new_buffer = ft_create_buffer(fd);
		ft_add_back(&buffer_list, new_buffer);
		return (new_buffer);
	}
	if (ft_search(fd, buffer_list) == NULL)
	{
		new_buffer = ft_create_buffer(fd);
		if (new_buffer == NULL)
			return (NULL);
		ft_add_back(&buffer_list, new_buffer);
	}
	return (buffer_list);
}

/*
Fucntion that gets the line , we search \n char or we take the full pointer 
if we do not find the char because we only enter in this function
if we found the line delimiter OR bytes_read == 0
*/
char	*ft_get_line(char *buffer, char c)
{
	size_t	noline_size;
	size_t	buffer_size;
	char	*end_line;
	char	*line;

	buffer_size = ft_strlen(buffer);
	if (buffer_size == 0)
		return (NULL);
	end_line = ft_strchr(buffer, c);
	if (buffer_size > 0 && end_line == NULL)
		line = ft_substr(buffer, 0, buffer_size);
	else
	{
		noline_size = ft_strlen(end_line);
		line = ft_substr(buffer, 0, buffer_size - noline_size);
	}
	return (line);
}

/*
Here we update the buffer, we remove the "line part" of the total buffer.
*/
char	*ft_update_buffer(char *buffer, char c)
{
	size_t	buffer_size;
	size_t	noline_size;
	char	*new_buffer;
	char	*end_line;

	buffer_size = ft_strlen(buffer);
	end_line = ft_strchr(buffer, c);
	if (end_line != NULL)
	{
		noline_size = ft_strlen(end_line);
		new_buffer = ft_substr(buffer, buffer_size - noline_size + 1,
				buffer_size);
	}
	else
	{
		new_buffer = ft_substr(buffer, 0, 0);
	}
	free (buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	int					bytes_read;
	static t_buffer		*buffer_list;
	t_buffer			*buffer;
	char				read_buffer[BUFFER_SIZE + 1];
	char				*line;

	buffer_list = bonus_init_buffer(buffer_list, fd);
	if (buffer_list == NULL)
		return (NULL);
	buffer = ft_search(fd, buffer_list);
	if (buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (ft_strchr(buffer->content, '\n') == NULL && bytes_read > 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		read_buffer[bytes_read] = '\0';
		buffer->content = ft_strjoin(buffer->content, read_buffer);
	}
	line = ft_get_line(buffer->content, '\n');
	buffer->content = ft_update_buffer(buffer->content, '\n');
	return (line);
}
