/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:42:31 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/07 00:30:39 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 40
# endif

# include <stddef.h>

typedef struct s_buffer
{
	char	*content;
	size_t	size;
}	t_buffer;

char		*get_next_line(int fd);
int			find_char(t_buffer *buffer, char c);
//t_buffer    *ft_update_buffer(t_buffer *buffer, char *src, size_t bytes);
int			ft_update_buffer(int fd, t_buffer *buffer);
t_buffer	*ft_add_text_2_buffer(t_buffer *buffer, char *src, size_t bytes);
char		*shift_buffer(t_buffer *buffer, size_t pos_char);
char		*ft_strndup(char *src, int to);
t_buffer	*init_buffer(t_buffer *buffer);

#endif
