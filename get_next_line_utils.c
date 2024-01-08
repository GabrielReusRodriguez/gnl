/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:50:04 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/08 00:18:17 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
Obtiene la longitud de un string
*/
size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

/*
Une los punteros que le pasamos por parámetro
*/
char	*ft_strjoin(char *buffer, char *read)
{
	char	*joined;
	size_t	size_buffer;
	size_t	size_read;
	size_t	i;

	size_buffer = ft_strlen(buffer);
	size_read = ft_strlen(read);
	joined = (char *)malloc(size_buffer + size_read + 1);
	if (joined == NULL)
		return (NULL);
	i = 0;
	while (i < size_buffer)
	{
		joined[i] = buffer[i];
		i++;
	}
	i = 0;
	while (i < size_read)
	{
		joined[size_buffer + i] = read[i];
		i++;
	}
	joined[size_buffer + size_read] = '\0';
	free(buffer);
	return (joined);
}

/*
Check si encuentra el caracter c en el buffer.
*/
char	*ft_strchr(char *buffer, char c)
{
	while (*buffer != '\0')
	{
		if (*buffer == c)
			return (buffer);
		buffer++;
	}
	return (NULL);
}

char	*ft_substr(char *buffer, size_t start, size_t end)
{
	size_t	size;
	size_t	i;
	char	*substr;

	size = end - start;
	substr = (char *)malloc(size + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		substr[i] = buffer[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
