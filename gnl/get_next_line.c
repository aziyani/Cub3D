/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:45:15 by aziyani           #+#    #+#             */
/*   Updated: 2022/12/12 13:17:32 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*next_line(char	*saver, int fd)
{
	char	*buffer;
	int		i;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	i = 1;
	while (i != 0 && !(ft_strchr(saver, '\n')))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
		{
			free(saver);
			free(buffer);
			saver = 0;
			return (0);
		}
		buffer[i] = '\0';
		saver = ft_strjoin(saver, buffer);
	}
	free(buffer);
	return (saver);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*saver;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	saver = next_line(saver, fd);
	if (!saver)
		return (0);
	if (saver[0] == '\0')
	{
		free(saver);
		saver = NULL;
		return (NULL);
	}
	line = cline(saver);
	saver = bowl(saver);
	return (line);
}
