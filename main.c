/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:04:29 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/07 02:03:14 by greus-ro         ###   ########.fr       */
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

	if (argc != 2)
	{
		printf("ERROR en argumentos\n");
		return (1);
	}
	fd = open(argv[1],O_RDONLY);
	if(fd < 0)
	{
		printf("Error al abrir el descriptor de fichero");
		return (1);
	}
	while((line= get_next_line(fd)) != NULL)
	{
		printf("<LINE>_%s_</LINE>\n\n",line);
		free(line);
	}
	close(fd);	
	return (0);
}
