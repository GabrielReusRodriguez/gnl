/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:41:44 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/07 01:13:58 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h> 
#include "get_next_line.h"

t_buffer	*init_buffer(t_buffer *buffer)
{
	if (buffer == NULL)
	{
		buffer = (t_buffer *)malloc(sizeof(t_buffer));
		if (buffer == NULL)
			return (NULL);
		buffer->size = 0;
		buffer->content = (char *)malloc(buffer->size);
		buffer->content[0] = '\0';
	}
	return (buffer);
}

char	*get_last_line(t_buffer *buffer)
{
		char	*ptr;
		
		ptr = ft_strndup(buffer->content, buffer->size);
		free (buffer->content);
		buffer->content = NULL;
		return (ptr);
}

char	*get_next_line(int fd)
{
	static t_buffer			*buffer;
	int						pos_char;
	int						bytes_read;
	char					*ptr;

	ptr = NULL;
	buffer = init_buffer(buffer);
	if (buffer->content == NULL)
		return (NULL);
	pos_char = -1;
	bytes_read = 1;
	while (pos_char == -1 && bytes_read != 0)
	{
		pos_char = find_char(buffer, '\n');
		if (pos_char != -1)
		{
			ptr = ft_strndup(buffer->content, pos_char);
			if (shift_buffer(buffer, pos_char + 1) == NULL)
				return (NULL);
			return (ptr);
		}
		bytes_read = ft_update_buffer(fd, buffer);
	}
	return (get_last_line(buffer));
}

/*
char	*get_next_line(int fd)
{
	static t_buffer			*buffer;
	int						pos_char;
	int						bytes_read;
	char					*ptr;

	ptr = NULL;
	buffer = init_buffer(buffer);
	bytes_read = 1;
	pos_char = -1;
	while (pos_char == -1 && bytes_read != 0)
	{
		pos_char = find_char(buffer, '\n');
		if (pos_char != -1)
		{
			ptr = ft_strndup(buffer->content, pos_char);
			if (shift_buffer(buffer, pos_char + 1) == NULL)
				return (NULL);
			return (ptr);
		}
		bytes_read = ft_update_buffer(fd, buffer);
	}
	if (bytes_read == 0)
	{
		ptr = ft_strndup(buffer->content, buffer->size);
		free (buffer->content);
		buffer->content = NULL;
		return (ptr);
	}
	return (NULL);
}

*/