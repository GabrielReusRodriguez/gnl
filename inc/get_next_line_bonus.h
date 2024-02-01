/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:36:38 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/23 22:21:50 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>

int			ft_strchr(char *src, char *c);
char		*ft_substr(const char *src, size_t start, size_t len);
char		*ft_strjoin(const char *s1, const char *s2);
size_t		ft_strlen(const char *s1);
void		*free_ptr(char **ptr);

char		*get_line_from_buffer(char **buffer, int num_bytes_read);
char		*read_line(char **buffer, int fd);
void		*update_buffer(char *buffer, char *read_buff, int num_bytes_read);
char		*get_next_line(int fd);
void		*get_buffer(char **buffers, int fd);

#endif
