/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoelho <fcoelho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 23:01:18 by fcoelho           #+#    #+#             */
/*   Updated: 2020/02/18 16:46:07 by fcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		*ft_calloc(size_t count, size_t size)
{
	void	*cllc;

	if (!(cllc = malloc(size * count)))
		return (NULL);
	ft_memset(cllc, 0, size * count);
	return (cllc);
}

static char		*putlil(char const *str, unsigned int len)
{
	unsigned int	i;
	char			*line;

	line = ft_calloc(1, len + 1);
	i = 0;
	while (i < len)
	{
		line[i] = str[i];
		i++;
	}
	return (line);
}

static int		mgk(char **str, char **line)
{
	unsigned int	len;
	char			*temp;

	len = 0;
	while ((*str)[len] != '\n' && (*str)[len])
		len++;
	if ((*str)[len] == '\n')
	{
		*line = putlil(&(*str)[0], len + 1);
		temp = ft_strdup(&((*str)[len + 1]));
		free(*str);
		*str = temp;
		if ((*str)[0] == '\0')
			free(*str);
	}
	else
	{
		*line = ft_strdup(*str);
		if (str != NULL && *str != NULL)
		{
			free(*str);
			*str = NULL;
		}
	}
	return (1);
}

static int		raux(char **str, char **line, int retaux, int fd)
{
	if (retaux < 0)
		return (-1);
	else if (retaux == 0 && str[fd] == NULL)
		return (0);
	else
		return (mgk(&str[fd], line));
}

int				get_next_line(int fd, char **line)
{
	int			retaux;
	char		buffer[BUFFER_SIZE + 1];
	static char *str[4096];
	char		*temp;

	if (fd < 0 && line == NULL)
		return (-1);
	while ((retaux = read(fd, &buffer, BUFFER_SIZE)) > 0)
	{
		buffer[retaux] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(str[fd], buffer);
			free(str[fd]);
			str[fd] = temp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (raux(str, line, retaux, fd));
}
