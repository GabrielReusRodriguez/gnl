/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:41:44 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/06 02:28:10 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <unistd.h> 
#include "get_next_line.h"


char	*get_next_line(int fd)
{

	static t_buffer			*buffer;
	char					temp_buffer[BUFFER_SIZE];
	int						pos_char;
	int						bytes_read;
	char					*ptr;

	ptr = NULL;
	bytes_read = 1;
	buffer = init_buffer(buffer);
	pos_char = find_char(buffer, '\n');
	if (pos_char != -1)
	{
		ptr = ft_strndup(buffer->content, pos_char);
		if (shift_buffer(buffer, pos_char + 1) == NULL)
			return (NULL);
		return (ptr);
	}
	pos_char = -1;
	while (pos_char == -1 && bytes_read != 0)
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		buffer = ft_update_buffer(buffer, temp_buffer, bytes_read);
		pos_char = find_char(buffer, '\n');
		if(pos_char != -1)
		{
			ptr = ft_strndup(buffer->content, pos_char);
			if (shift_buffer(buffer, pos_char + 1) == NULL)
				return (NULL);
			return (ptr);
		}
	}
	if (bytes_read < 0)
	{
		return (NULL);
	}
	return (ptr);
}
