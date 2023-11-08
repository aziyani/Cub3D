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

#include "Cub3D.h"

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
	while (s[i])
	{
		if (s[i] != ' ')
			str[j++] = s[i++];
		else
			i++;
	}
	return (str);
}
char * check_f(char *str){
	int i = 0;
	int j = 0;
	char *res = malloc(ft_strlen(str));
	while (str[i]){
		if (str[i] == 'F')
			i++;
		res[j] = str[i];
		i++;
		j++;
	}
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
	return res;
}
int check_floor(char *s, t_data *cub)
{
	int j;
	char **str;
	char **str1;
	char	*s1;

	int i = 0;

	s1 = check_f(s);
	// sc = check_ceil(s);
	str = ft_split(s1, ',');
	printf("s1 ==== %s\n\n\n", s1);
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
		printf("%d\n", cub->floor[0]);
		if (cub->floor[0] < 0 || cub->floor[0] > 256)
			ft_errorr("more than 255");
		cub->floor[1] = ft_atoi(str[1]);
		if (cub->floor[1] < 0 || cub->floor[1] > 256)
			ft_errorr("more than 255");
		cub->floor[2] = ft_atoi(str[2]);
		if (cub->floor[2] < 0 || cub->floor[2] > 256)
			ft_errorr("more than 255");
		printf("F === r=%d g=%d b=%d\n", cub->floor[0], cub->floor[1], cub->floor[2]);
	}
	else
		ft_errorr("bad arguments");
	return 1;
}


void check_ceil(char *s, t_data *cub){
	int j;
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
		printf("C === r=%d g=%d b=%d\n", cub->sky[0], cub->sky[1], cub->sky[2]);
	}
	else
		ft_errorr("bad arguments");
}

void check_map(t_data *data, int i)
{
	int j;

	while (data->map_db[i])
	{
		j = 0;
		while (data->map_db[i][j])
		{
			if (data->map_db[i][j] == '0')
			{
				if (data->map_db[i][j + 1] == ' ' || data->map_db[i][j + 1] == '\0')
					ft_errorr("211");
				if (data->map_db[i][j - 1] == ' ' || data->map_db[i][j - 1] == '\0')
					ft_errorr("213");
				if ((data->map_db[i] && data->map_db[i - 1][j] == ' ') || data->map_db[i - 1][j] == '\0')
					ft_errorr("215");
				if ((data->map_db[i] && data->map_db[i + 1][j] == ' ') || data->map_db[i + 1][j] == '\0')
					ft_errorr("217");
			}
			j++;
		}
		i++;
	}
}

void check_news(t_data *data, int i)
{
	int j;
	
	while (data->map_db[i])
	{
		j = 0;
		while (data->map_db[i][j])
		{
			// printf("[%d]", data->map_db[i][j]);
			if (data->map_db[i][j] != '1' && data->map_db[i][j] != '0' && data->map_db[i][j] != 'N' && data->map_db[i][j] != 'E' && data->map_db[i][j] != 'W' && data->map_db[i][j] != 'S' && data->map_db[i][j] != ' ' /*&& data->map_db[i][j] != '\n'*/)
				ft_errorr("your map not valid");
			j++;
		}
		i++;
	}
	
}

int part_two(t_data *data, int i) // checking the map part in the 2d array
{
	check_news(data, i);
	check_map(data, i);
	
	return (0);
}

int part_one(t_data *data) // checking the first lines of textures and colors
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
		if (ft_strlen(data->map_db[i]) == 0)
		{
			i++;
			continue;
		}
		s = ft_split(data->map_db[i], ' ');
		if (!ft_strncmp("NO", s[0], 3))
			check_path(s, ch.no);
		else if (!ft_strncmp("SO", s[0], 3))
			check_path(s, ch.so);
		else if (!ft_strncmp("WE", s[0], 3))
			check_path(s, ch.we);
		else if (!ft_strncmp("EA", s[0], 3))
			check_path(s, ch.ea);
		else if (!ft_strncmp("C", s[0], 2))
			check_ceil(data->map_db[i], data);
		else if (!ft_strncmp("F", s[0], 2))
			check_floor(data->map_db[i], data);
		else
			ft_errorr("invalid parametres!");
		j++;
		i++;
	}
	part_two(data, i);
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



void read_map(int fd, t_data *data, char **av)
{
	int i;
	int j;

	i = 0;
	j = count_map_lines(fd);
	data->map_db = (char **)malloc(sizeof(char *) * (j + 1));
	if (!data->map_db)
		ft_errorr("234");
	fd = open(av[1], O_RDONLY);
	while (i < j)
	{
		data->map_db[i] = get_next_line(fd);
		if (data->map_db[i][ft_strlen(data->map_db[i]) - 1] == '\n')
			data->map_db[i][ft_strlen(data->map_db[i]) - 1] = 0;
		i++;
	}
	data->map_db[j] = NULL;
}

int main(int ac, char **av)
{
	t_data *data;
	int fd;

	(void)(ac);
	data = malloc(sizeof(t_data));
	data->av = av[1];
	fd = open(av[1], O_RDONLY);
	read_map(fd, data, av);
	part_one(data);
}
