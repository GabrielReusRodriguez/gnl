/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 00:53:34 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/22 13:53:05 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int fd;
    char *line;

    //fd = open("./empty.txt", O_RDONLY);
    //fd = open("./nl.txt", O_RDONLY);
    //fd = open("./41nl.txt", O_RDONLY);
    fd = open("./1.txt", O_RDONLY);
    line = argv[0];
    argc++;
    while (line != NULL)
    {
        line = get_next_line(fd);
        printf("LINE: _%s_\n", line);
        free(line);
    }
    close (fd);
}