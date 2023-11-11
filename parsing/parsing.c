/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:40:51 by aziyani           #+#    #+#             */
/*   Updated: 2023/11/11 11:48:31 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../CUB3D.h"

int	part_two(s_main *m, int i)
{
	int	t;
	int	j;
	int	k;

	t = 0;
	k = 0;
	j = i;
	while (m->map_db[j])
	{
		j++;
		t++;
	}
	m->map = ft_calloc(sizeof(char *), t + 1);
	j = i;
	while (m->map_db[j])
	{
		m->map[k] = ft_strdup(m->map_db[j]);
		j++;
		k++;
	}
	{
		int	i;

		i = 0;
		while (m->map[i])
		{
			printf("%s\n", m->map[i]);
			i++;
		}
	}
	check_news(m, i);
	check_map(m, i);
	return (0);
}

int	part_one(s_main *m)
{
	int		i;
	int		j;
	char	**s;
	t_check	ch;

	ch = initialize_check();
	i = 0;
	j = 0;
	while (j < 6)
	{
		if (ft_strlen(m->map_db[i]) == 0)
		{
			i++;
			continue ;
		}
		s = ft_split(m->map_db[i], ' ');
		if (!s[0])
			ft_errorr("invalid parametres!");
		else if (!ft_strncmp("NO", s[0], 3))
			check_path(s, ch.no);
		else if (!ft_strncmp("SO", s[0], 3))
			check_path(s, ch.so);
		else if (!ft_strncmp("WE", s[0], 3))
			check_path(s, ch.we);
		else if (!ft_strncmp("EA", s[0], 3))
			check_path(s, ch.ea);
		else if (!ft_strncmp("C", s[0], 2))
			check_ceil(m->map_db[i], m);
		else if (!ft_strncmp("F", s[0], 2))
			check_floor(m->map_db[i], m);
		else
			ft_errorr("invalid parametres!");
		j++;
		i++;
	}
	part_two(m, i);
	return (0);
}

int	count_map_lines(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = "chihaja"; // 3tiniha chihaja bach dkhel lwhile hit makhashach tkon NULL
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

void	read_map(int fd, s_main *m, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = count_map_lines(fd);
	m->map_db = (char **)malloc(sizeof(char *) * (j + 1));
	if (!m->map_db)
		ft_errorr("234");
	fd = open(av[1], O_RDONLY);
	while (i < j)
	{
		m->map_db[i] = get_next_line(fd);
		if (m->map_db[i][ft_strlen(m->map_db[i]) - 1] == '\n')
			m->map_db[i][ft_strlen(m->map_db[i]) - 1] = '\0';
		i++;
	}
	m->map_db[j] = NULL;
}

int	main(int ac, char **av)
{
	s_main	*m;
	int		fd;

	(void)(ac);
	m = malloc(sizeof(s_main));
	m->av = av[1];
	fd = open(av[1], O_RDONLY);
	read_map(fd, m, av);
	part_one(m);
	// start_game(m);
}
