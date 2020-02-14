/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoelho <fcoelho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 23:07:08 by fcoelho           #+#    #+#             */
/*   Updated: 2020/02/14 05:23:10 by fcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (get_next_line(fd, &line) == 1)
			printf("%s", line);
	}
	return (0);
}
