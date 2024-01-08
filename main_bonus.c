/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 23:48:02 by gabriel           #+#    #+#             */
/*   Updated: 2024/01/07 23:48:04 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 2)
	{
		fd = open(argv[1],O_RDONLY);
		if(fd < 0)
		{
			printf("Error al abrir el descriptor de fichero");
			return (1);
		}
	}
	else
	{
		fd = 1;
	}
	while((line= get_next_line(fd)) != NULL)
	{
		printf("<LINE>_%s_</LINE>\n\n",line);
		free(line);
	}
	close(fd);	
	return (0);
}
