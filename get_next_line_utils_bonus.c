/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:50:04 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/08 21:23:29 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "get_next_line_bonus.h"

t_buffer	*ft_create_buffer(int fd)
{
	t_buffer	*buffer;

	buffer = (t_buffer *)malloc(sizeof(t_buffer));
	if (buffer == NULL)
		return (NULL);
	buffer->content = (char *)malloc(1);
	if (buffer->content == NULL)
		return (NULL);
	buffer->content[0] = '\0';
	buffer->fd = fd;
	buffer->next = NULL;
	return (buffer);
}

void	ft_add_back(t_buffer **buffer, t_buffer *new_buffer)
{
	t_buffer	*node;

	if (*buffer == NULL)
	{
		*buffer = new_buffer;
		return ;
	}
	node = *buffer;
	while (node->next != NULL)
		node = node->next;
	node->next = new_buffer;
}

t_buffer	*ft_search(int fd, t_buffer *buffer)
{
	t_buffer	*node;

	if (buffer == NULL)
		return (NULL);
	node = buffer;
	while (node->next != NULL)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	if (node->fd == fd)
		return (node);
	else
		return (NULL);
}
