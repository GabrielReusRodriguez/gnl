/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:42:31 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/07 23:45:12 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 40
# endif

# include <stddef.h>

char	*get_next_line(int fd);
char	*init_buffer(char *buffer);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *buffer, char *read);
char	*ft_strchr(char *buffer, char c);
char	*ft_substr(char *buffer, size_t start, size_t end);

#endif
