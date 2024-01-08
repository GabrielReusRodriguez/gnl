/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:42:31 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/08 21:26:36 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 40
# endif

# include <stddef.h>

typedef struct s_buffer
{
	int					fd;
	char				*content;
	struct s_buffer		*next;
}	t_buffer;

char		*get_next_line(int fd);
t_buffer	*ft_create_buffer(int fd);
void		ft_add_back(t_buffer **buffer, t_buffer *new_buffer);
t_buffer	*ft_search(int fd, t_buffer	*buffer);

#endif
