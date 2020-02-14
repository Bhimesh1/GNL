/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoelho <fcoelho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 23:01:18 by fcoelho           #+#    #+#             */
/*   Updated: 2020/02/14 05:32:42 by fcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int			ret;
	char		buffer[BUFFER_SIZE + 1];
	static char *str[4096];
	char		*temp = NULL;

	if (fd < 0 && line == NULL)
		return (-1);
	while ((ret = read(fd, &buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(str[fd], buffer);
			free(str[fd]);
			str[fd] = temp;
		}
		if (ft_strchr(str[fd], '\n'))
			break;
	}
	*line = ft_strdup(str[fd]);

	return (1);
}
