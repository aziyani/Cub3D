/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chyata.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:20:37 by aziyani           #+#    #+#             */
/*   Updated: 2023/11/11 16:07:16 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../CUB3D.h"

int	ft_count(char	*s1)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s1[i])
	{
		if (s1[i] == ',')
			count++;
		i++;
	}
	return (count);
}

int	count_map_lines(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = "chihaja";
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			i++;
		free(line);
	}
	close(fd);
	return (i);
}
