/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:42:31 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/08 00:39:49 by gabriel          ###   ########.fr       */
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
	int                 fd;
	char	            *content;
	struct s_buffer		*next;
}	t_buffer;

t_buffer	*ft_create_buffer(int fd);
void		ft_add_back(t_buffer **buffer, t_buffer *new_buffer);
t_buffer	*ft_search(int fd , t_buffer	*buffer);


#endif
