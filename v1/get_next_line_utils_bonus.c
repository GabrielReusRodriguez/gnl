/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:50:04 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/07 02:31:30 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	ft_update_buffer(int fd, t_buffer *buffer)
{
	int		bytes_read;
	char	temp_buffer[BUFFER_SIZE];

	bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
	ft_add_text_2_buffer(buffer, temp_buffer, bytes_read);
	return (bytes_read);
}

t_buffer	*ft_add_text_2_buffer(t_buffer *buffer, char *src, size_t bytes)
{
	char	*new_ptr;
	char	*old_ptr;
	size_t	i;

	new_ptr = (char *)malloc(buffer->size + bytes);
	if (new_ptr == NULL)
		return (NULL);
	i = 0;
	while (i < buffer->size)
	{
		new_ptr[i] = buffer->content[i];
		i++;
	}
	i = 0;
	while (i < bytes)
	{
		new_ptr[buffer->size + i] = src[i];
		i++;
	}
	old_ptr = buffer->content;
	buffer->content = new_ptr;
	free(old_ptr);
	buffer->size = buffer->size + bytes;
	return (buffer);
}

char	*ft_strndup(char *src, int to)
{
	int		i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(to + 1);
	if (dup == NULL)
		return (NULL);
	while (i < to)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*shift_buffer(t_buffer *buffer, size_t pos_char)
{
	size_t	i;
	char	*old_content;
	char	*new_content;

	i = 0;
	new_content = (char *)malloc(buffer->size - pos_char);
	if (new_content == NULL)
		return (NULL);
	old_content = buffer->content;
	while (i < buffer->size - pos_char)
	{
		new_content[i] = buffer->content[pos_char + i];
		i++;
	}
	buffer->content = new_content;
	buffer->size = buffer->size - pos_char;
	free (old_content);
	return (new_content);
}

int	find_char(t_buffer *buffer, char c)
{
	size_t	i;

	i = 0;
	while (i < buffer->size && buffer->content[i] != c)
		i++;
	if (i < buffer->size && buffer->content[i] == c)
		return (i);
	else
		return (-1);
}
