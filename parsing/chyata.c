/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chyata.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:20:37 by aziyani           #+#    #+#             */
/*   Updated: 2023/11/16 22:33:28 by aziyani          ###   ########.fr       */
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

int	count_map_lines(int fd, int *asmax)
{
	int		i;
	char	*line;

	i = 0;
	line = "chihaja";
	while (line)
	{
		line = get_next_line(fd);
		if ((int)ft_strlen(line) > (*asmax))
			*asmax = ft_strlen(line);
		if (line)
			i++;
		free(line);
	}
	close(fd);
	return (i);
}

char	*ft_fku(char *x, int max)
{
	char	*dst;

	dst = ft_calloc(max + 1, sizeof(1));
	ft_memmove(dst, x, max);
	free(x);
	return (dst);
}

int	valid_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			return (1);
		i++;
	}
	return (0);
}
