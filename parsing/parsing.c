// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   parsingc.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/10/03 22:40:51 by aziyani           #+#    #+#             */
// /*   Updated: 2023/10/07 15:39:54 by aziyani          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../CUB3D.h"

void ft_errorr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (2, &s[i], 1);
		i++;
	}
	write(2, "\n", 1);
	exit(1);
}

t_check initialize_check(void)
{
	t_check ch;
	ch.no = 0;
	ch.so = 0;
	ch.ea = 0;
	ch.we = 0;
	ch.c = 0;
	ch.f = 0;
	return ch;
}

int check_path(char **s, int ch)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	if (i != 2)
		ft_errorr("49");
	int fd;
	if (ch == 1)
		ft_errorr("52");
	ch = 1;

	fd = open(s[1], O_RDONLY);
	if (fd == -1)
		ft_errorr("57");
	return (1);
}

char	*skip_s(char *s)
{
	int i;
	int	j;
	char	*str;

	i = 0;
	j = 0;
	str = NULL;
	while (s[i])
	{
		if (s[i] != ' ')
			str[j++] = s[i++];
		else
			i++;
	}
	return (str);
}
char * check_f(char *str)
{
	char *res;
	int i = 0;
	int j = 0;
	res = malloc(ft_strlen(str));
	while (str[i])
	{
		if (str[i] == 'F')
			i++;
		res[j] = str[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return res;
}
char * check_c(char *str){
	int i = 0;
	int j = 0;
	char *res = malloc(ft_strlen(str));
	while (str[i]){
		if (str[i] == 'C')
			i++;
		res[j] = str[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return res;
}
int check_floor(char *s, s_main *cub)
{
	int j;
	char **str;
	char	*s1;

	int i = 0;

	s1 = check_f(s);
	// sc = check_ceil(s);
	// printf("s1 ==== %s\n\n\n", s1);
	str = ft_split(s1, ',');
	int count = 0;
	while (s1[i])
	{
		if (s1[i] == ','){
			count++;
		}
		i++;
	}
	if (str[0] && str[1] && str[2] && !str[3] && count == 2)
	{
		j = 0;
		cub->floor[0] = ft_atoi(str[0]);
		// printf("%d\n", cub->floor[0]);
		if (cub->floor[0] < 0 || cub->floor[0] > 256)
			ft_errorr("more than 255");
		cub->floor[1] = ft_atoi(str[1]);
		if (cub->floor[1] < 0 || cub->floor[1] > 256)
			ft_errorr("more than 255");
		cub->floor[2] = ft_atoi(str[2]);
		if (cub->floor[2] < 0 || cub->floor[2] > 256)
			ft_errorr("more than 255");
		// printf("F === r=%d g=%d b=%d\n", cub->floor[0], cub->floor[1], cub->floor[2]);
	}
	else
		ft_errorr("bad arguments");
	return 1;
}


void check_ceil(char *s, s_main *cub){
	char **str;
	char	*s1;

	int i = 0;

	s1 = check_c(s);
	str = ft_split(s1, ',');
	int count  =0;
	while (s1[i])
	{
		if (s1[i] == ','){
			count++;
		}
		i++;
	}
	if (str[0] && str[1] && str[2] && !str[3] && count == 2)
	{
		cub->sky[0] = ft_atoi(str[0]);
		if (cub->sky[0] < 0 || cub->sky[0] > 256)
			ft_errorr("more than 255");
		cub->sky[1] = ft_atoi(str[1]);
		if (cub->sky[1] < 0 || cub->sky[1] > 256)
			ft_errorr("more than 255");
		cub->sky[2] = ft_atoi(str[2]);
		if (cub->sky[2] < 0 || cub->sky[2] > 256)
			ft_errorr("more than 255");
		// printf("C === r=%d g=%d b=%d\n", cub->sky[0], cub->sky[1], cub->sky[2]);
	}
	else
		ft_errorr("bad arguments");
}

void check_map(s_main *m, int i)
{
	int j;

	while (m->map_db[i])
	{
		j = 0;
		// printf("%d\n")
		while (m->map_db[i][j])
		{
			if (m->map_db[i][j] == '0')
			{
				if (m->map_db[i][j + 1] == ' ' || m->map_db[i][j + 1] == '\0')
					ft_errorr("211");
				if (m->map_db[i][j - 1] == ' ' || m->map_db[i][j - 1] == '\0')
					ft_errorr("213");
				if ((m->map_db[i] && m->map_db[i - 1][j] == ' ') || m->map_db[i - 1][j] == '\0')
					ft_errorr("215");
				if ((m->map_db[i] && m->map_db[i + 1][j] == ' ') || m->map_db[i + 1][j] == '\0')
					ft_errorr("217");
			}
			j++;
		}
		i++;
	}
}

void check_news(s_main *m, int i)
{
	int j;
	
	while (m->map_db[i])
	{
		j = 0;
		while (m->map_db[i][j])
		{
			if (m->map_db[i][j] != '1' && m->map_db[i][j] != '0' && m->map_db[i][j] != 'N' && m->map_db[i][j] != 'E' && m->map_db[i][j] != 'W' && m->map_db[i][j] != 'S' && m->map_db[i][j] != ' ')
				ft_errorr("your map not valid");
			j++;
		}
		i++;
	}
	
}

int part_two(s_main *m, int i)
{
	int t = 0;
	int j = i, k = 0;
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
		int i = 0;
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

int part_one(s_main *m)
{
	int i;
	int	j;
	char **s;
	t_check ch;

	ch = initialize_check();
	i = 0;
	j = 0;
	while (j < 6)
	{
		if (ft_strlen(m->map_db[i]) == 0)
		{
			i++;
			continue;
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

int count_map_lines(int fd)
{
	int i;
	char *line;

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

int skip_spaces(char *s, int index)
{
	int j;

	j = index;
	while (s[j] == ' ')
		j++;
	return (j);
}



void read_map(int fd, s_main *m, char **av)
{
	int i;
	int j;

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

int main(int ac, char **av)
{
	s_main *m;
	int fd;

	(void)(ac);
	m = malloc(sizeof(s_main));
	m->av = av[1];
	fd = open(av[1], O_RDONLY);
	read_map(fd, m, av);
	part_one(m);
	// start_game(m);
}
