/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 23:48:02 by gabriel           #+#    #+#             */
/*   Updated: 2024/01/08 21:20:57 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd;
	int		fd_ex1;
	int		fd_ex2;
	int		fd_ex3;
	char	*line;


	fd = 1;
	fd_ex1 = fd = open("./examples/ex1.txt",O_RDONLY);
	fd_ex2 = fd = open("./examples/ex2.txt",O_RDONLY);
	fd_ex3 = fd = open("./examples/ex3.txt",O_RDONLY);

	if ((line = get_next_line(fd_ex1)) != NULL)
	{
		printf("<LINE>_%s_</LINE>\n\n",line);
		free(line);
	}

	if ((line = get_next_line(fd_ex2)) != NULL)
	{
		printf("<LINE>_%s_</LINE>\n\n",line);
		free(line);
	}

	if ((line = get_next_line(fd_ex1)) != NULL)
	{
		printf("<LINE>_%s_</LINE>\n\n",line);
		free(line);
	}

	if ((line = get_next_line(fd_ex3)) != NULL)
	{
		printf("<LINE>_%s_</LINE>\n\n",line);
		free(line);
	}
/*
	if ((line = get_next_line(1)) != NULL)
	{
		printf("<LINE>_%s_</LINE>\n\n",line);
		free(line);
	}
*/
	if ((line = get_next_line(fd_ex2)) != NULL)
	{
		printf("<LINE>_%s_</LINE>\n\n",line);
		free(line);
	}
	
	if ((line = get_next_line(fd_ex1)) != NULL)
	{
		printf("<LINE>_%s_</LINE>\n\n",line);
		free(line);
	}

	if ((line = get_next_line(fd_ex2)) != NULL)
	{
		printf("<LINE>_%s_</LINE>\n\n",line);
		free(line);
	}



/*
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
	*/

	
	return (0);
}
