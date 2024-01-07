/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:50:04 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/07 03:21:30 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

/*
Se encarga de leer del File descriptor y de añadirel texto leido al 
buffer.
*/
int	ft_update_buffer(int fd, t_buffer *buffer)
{
	int		bytes_read;
	char	temp_buffer[BUFFER_SIZE];

	bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
	ft_add_text_2_buffer(buffer, temp_buffer, bytes_read);
	return (bytes_read);
}

/*
Se encarga de añadir el texto leido en el read al buffer que tenemos 
, previamente hace un malloc de un nuevo puntero y un free del antiguo 
para evitar memory leaks. 
Ojo xq se reserva memoria para buffer>size +bytes + 1 ya que hay que poner el \0
*/
t_buffer	*ft_add_text_2_buffer(t_buffer *buffer, char *src, size_t bytes)
{
	char	*new_ptr;
	char	*old_ptr;
	size_t	i;

	new_ptr = (char *)malloc(buffer->size + bytes + 1);
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
	new_ptr[buffer->size + bytes] = '\0';
	old_ptr = buffer->content;
	buffer->content = new_ptr;
	free(old_ptr);
	buffer->size = buffer->size + bytes;
	return (buffer);
}

/*
Duplica el puntero hasta la posicion "to" haciendo un malloc.
*/
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

/*
Crea un puntero con el contenido de las poiciones pos_char hasta el final.
*/
char	*shift_buffer(t_buffer *buffer, size_t pos_char)
{
	size_t	i;
	char	*old_content;
	char	*new_content;

	i = 0;
	new_content = (char *)malloc(buffer->size - pos_char + 1);
	if (new_content == NULL)
		return (NULL);
	old_content = buffer->content;
	while (i < buffer->size - pos_char)
	{
		new_content[i] = buffer->content[pos_char + i];
		i++;
	}
	new_content[buffer->size - pos_char] = '\0';
	buffer->content = new_content;
	buffer->size = buffer->size - pos_char;
	free (old_content);
	return (new_content);
}

/*
Check si encuentra el caracter c en el buffer.
*/
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
