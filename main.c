/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:23:53 by aasselma          #+#    #+#             */
/*   Updated: 2023/11/09 19:12:14 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUB3D.h"

void	draw_map(mlx_image_t *img, int32_t y, int32_t x, int32_t clr)
{
	int32_t	w;
	int32_t	h;
	int32_t	s;

	s = CUB_SIZE;
	w = s * x;
	h = s * y;
	y = 0;
	x = 0;
	while(y != s)
	{
		while (x != CUB_SIZE)
		{
			mlx_put_pixel(img, w / MIN, h / MIN, clr);
			x++;
			w++;
		}
		x = 0;
		w -= CUB_SIZE;
		h++;
		y++;
	}
}


void	draw_line1(s_main *m, float x2, float y2)
{
	float	xdiff;	
	float	ydiff;
	float	max_diff;
	float		rpeat_x;
	float		rpeat_y;
	int		i;

	xdiff = x2 - m->s_x;
	ydiff = y2 - m->s_y;
	max_diff = fabs(xdiff);
	if (fabs(xdiff) < fabs(ydiff))
		max_diff = fabs(ydiff);
	xdiff = xdiff / max_diff;
	ydiff = ydiff / max_diff;
	i = 0;
	rpeat_x = m->s_x;
	rpeat_y = m->s_y;
	while(i < max_diff)
	{
		if (rpeat_x >= 0 && rpeat_y >= 0 && rpeat_x < (m->size[0] * CUB_SIZE) && rpeat_y < (m->size[1] * CUB_SIZE))
			mlx_put_pixel(m->image, (int) (rpeat_x / MIN), (int) (rpeat_y / MIN), 0x53f0FFF);
		rpeat_x += xdiff;
		rpeat_y += ydiff;
		i++;
	}
}

void	draw_line(s_main *m, t_point p1, t_point p2)
{
	float	xdiff;	
	float	ydiff;
	float	max_diff;
	float	rpeat_x;
	float	rpeat_y;
	int		i;

	xdiff = p2.x - p1.x;
	ydiff = p2.y - p1.y;
	max_diff = fabs(xdiff);
	if (fabs(xdiff) < fabs(ydiff))
		max_diff = fabs(ydiff);
	xdiff = xdiff / max_diff;
	ydiff = ydiff / max_diff;
	i = 0;
	rpeat_x = p1.x;
	rpeat_y = p1.y;
	while(i < max_diff)
	{
		if ((rpeat_x > 0 && rpeat_x <= WIDTH) && (rpeat_y > 0 && rpeat_y <= HEIGH))
			mlx_put_pixel(m->g_image, (int) (rpeat_x), (int) (rpeat_y), 0x8d99aeFF);
		rpeat_x += xdiff;
		rpeat_y += ydiff;
		i++;
	}
}

void	ray_casting__(s_main *m, float pov)
{
	float	w_x;
	float	w_y;
	float	f_x;
	float	f_y;
	
	w_y = 0;
	w_x = 0;
	if (pov == 90 || pov == 270)
		return ;
	if (pov > 90 && pov < 270)
	{
		w_x = ((int) (m->s_x / CUB_SIZE) - 0.000001) * CUB_SIZE;
		f_x	= -CUB_SIZE;
	}
	else
	{
		w_x = ((int) (m->s_x / CUB_SIZE) + 1) * CUB_SIZE;
		f_x	= CUB_SIZE;
	}
	w_y = (-(m->s_x - w_x) * tan(pov * RAD)) + m->s_y;
	f_y = (f_x * tan(pov * RAD));
	while(true)
	{
		if ((((int)(w_y) / 50) < m->size[0] && ((int)(w_x) / 50) < m->size[1])
			&& ((int)(w_y) / 50) >= 0 && ((int)(w_x) / 50) >= 0)
		{
			printf("w_y : %f\n", (w_y / 50));
			printf("w_x : %f\n", (w_x / 30));
			printf("char: %c\n", m->map[(int)(w_y) / 50][(int)(w_x / 50)]);
			if (m->map[(int)(w_y) / 50][(int)(w_x / 50)] == '1')
				break;
		}
		else
			break;
		w_y += f_y;
		w_x += f_x;
		printf("w_y : %f\n", (w_y / 50));
		printf("w_x : %f\n", (w_x / 30));
		// exit(0);
	}
	m->ofo9i_x = w_x;
	m->ofo9i_y = w_y;
}

void	ray_casting(s_main	*m, float pov)
{
	float	w_x;
	float	w_y;
	float	f_x;
	float	f_y;
	
	w_y = 0;
	w_x = 0;
	if (pov == 0 || pov == 180 || pov == 360)
		return ;
	if (pov > 180 && pov < 360)
	{
		w_y = (((int)(m->s_y / CUB_SIZE) - 0.000001) * CUB_SIZE);
		f_y	= -CUB_SIZE;
	}
	else
	{
		w_y = ((int) (m->s_y / CUB_SIZE) + 1) * CUB_SIZE;
		f_y	= CUB_SIZE;
	}
	w_x = (-(m->s_y - w_y) / tan(pov * RAD)) + m->s_x;
	f_x = (f_y / tan(pov * RAD));
	while(1)
	{
		if ((((int)(w_y) / 50) <= m->size[0] && ((int)(w_x) / 50) <= m->size[1])
			&& ((int)(w_y) / 50) >= 0 && ((int)(w_x) / 50) >= 0)
		{
			if (m->map[(int)(w_y) / 50][(int)(w_x / 50)] == '1')
				break;
		}
		else
			break;
		w_y += f_y;
		w_x += f_x;
	}
	m->amodi_x = w_x;
	m->amodi_y = w_y;
}

void	get_distance(s_main	*m, float  pov)
{
	m->amodi_x = m->s_x + 1;
	m->amodi_y = m->s_y + 1;
	m->ofo9i_x = m->s_x + 1;
	m->ofo9i_y = m->s_y + 1;
	ray_casting__(m, pov);
	ray_casting(m, pov);
	float	a;
	float	b;
	float	c1;
	float	c2;

	a = m->s_x - m->amodi_x;
	b = m->s_y - m->amodi_y;
	c1 = sqrt((a * a) + (b * b));
	a = m->s_x - m->ofo9i_x;
	b = m->s_y - m->ofo9i_y;
	c2 = sqrt((a * a) + (b * b));
	if (c2 <= c1)
	{
		m->goal_x = m->ofo9i_x;
		m->goal_y = m->ofo9i_y;
		m->distance = c2;
	}
	else
	{
		m->goal_x = m->amodi_x;
		m->goal_y = m->amodi_y;
		m->distance = c1;
	}
	draw_line1(m, m->goal_x, m->goal_y);
	m->distance = m->distance * cos((pov - m->pov) * RAD);
}

void	draw_walls(s_main *m, int i)
{
	t_point p1;
	t_point p2;
	float	v;

	v = (HEIGH / m->distance) * CUB_SIZE;
	p1.x = i;
	p1.y = (HEIGH / 2) - (v / 2);
	p2.x = i;
	p2.y = (HEIGH / 2) + (v / 2);
	draw_line(m, p1, p2);
}

void	hook(void* param)
{
	s_main*		m;
	uint32_t	y;
	uint32_t	x;
	m = param;

	y = 0;
	while(y != 11)
	{
		x = 0;
		while (m->map[y][x])
		{
			if (m->map[y][x] == '1')
				draw_map(m->image, y, x, W_COLOR);
			else if (m->map[y][x] != '1')
				draw_map(m->image, y, x, G_COLOR);
			if (m->map[y][x] == 'N' || m->map[y][x] == 'S' 
				|| m->map[y][x] == 'E' || m->map[y][x] == 'W')
				{
					m->map[y][x] = '0';
					m->s_x = (x * CUB_SIZE) + 18;
					m->s_y = (y * CUB_SIZE) + 18;
				}
			x++;
		}
		y++;
	}
	int	i = 0;
	float	pov = m->pov - 30;
	float	fov = 60;
	float	rays = WIDTH;
	int	yy;
	int	xx;
	yy = 0;
	while(yy != HEIGH)
	{
		xx = 0;
		while(xx != WIDTH)
		{
			if (yy <= (HEIGH / 2))
				mlx_put_pixel(m->g_image, xx++, yy, 0x87CEEBFF);
			else
				mlx_put_pixel(m->g_image, xx++, yy, 0x151F2CFF);
		}
		yy++;
	}
	while(i <= rays)
	{
		if (pov > 360)
			pov -= 360;
		else if (pov < 0)
			pov += 360;
		get_distance(m, pov);
		draw_walls(m, i);
		pov += fov / rays;
		i++;
	}
}

void copy2DArrayToDoublePointer(char*** doublePointer, char sourceArray[][11], int rows, int cols)
{
	int j;
	int i = 0;
	*doublePointer = (char**)malloc(rows * sizeof(char*));

	for (; i < rows; i++)
	{
		j = 0;
		(*doublePointer)[i] = (char*)malloc(cols * sizeof(char));
		for (; j < cols; j++) {
			(*doublePointer)[i][j] = sourceArray[i][j];
		}
		(*doublePointer)[i][j] = '\0';
	}
	
}

int	check_nm(s_main *m, float y, float x, int sign)
{
	float	s_y;
	float	s_x;

	s_y	= (m->s_y + (y * 5));
	s_x	= (m->s_x + (x * 5));
	if (sign == 0)
	{
		s_y	= (m->s_y - (y * 5));
		s_x	= (m->s_x - (x * 5));
	}
	// printf("%c\n", m->map[(int)(s_y / 50)][(int)(s_x / 50)]);
	if (m->map[(int)(s_y / 50)][(int)(s_x / 50)] == '1')
		return (0);
	return (1);
}

void	player_moves(void	*param)
{
	s_main	*m;

	m = param;
	if (mlx_is_key_down(m->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(m->mlx);
	if (mlx_is_key_down(m->mlx, MLX_KEY_W) && check_nm(m, sin(m->pov * RAD), cos(m->pov * RAD), 1))
	{
		m->s_y += sin(m->pov * RAD);
		m->s_x += cos(m->pov * RAD);
	}
	else if (mlx_is_key_down(m->mlx, MLX_KEY_S) && check_nm(m, sin(m->pov * RAD), cos(m->pov * RAD), 0))
	{
		m->s_y -= sin(m->pov * RAD);
		m->s_x -= cos(m->pov * RAD);
	}
	else if (mlx_is_key_down(m->mlx, MLX_KEY_A)
		&& check_nm(m, sin((m->pov - 90) * RAD), cos((m->pov - 90) * RAD), 1))
	{
		m->s_y += sin((m->pov - 90) * RAD);
		m->s_x += cos((m->pov - 90) * RAD);
	}
	else if (mlx_is_key_down(m->mlx, MLX_KEY_D)
		&& check_nm(m, sin((m->pov - 90) * RAD), cos((m->pov - 90) * RAD), 0))
	{
		m->s_y -= sin((m->pov - 90) * RAD);
		m->s_x -= cos((m->pov - 90) * RAD);
	}
	if (mlx_is_key_down(m->mlx, MLX_KEY_RIGHT))
		m->pov += 1;
	else if (mlx_is_key_down(m->mlx, MLX_KEY_LEFT))
		m->pov -= 1;
	if (m->pov > 360)
		m->pov -= 360;
	if (m->pov < 0)
		m->pov += 360;
}

int start_game(s_main *m)
{
	m->size = malloc(2 * sizeof(int32_t));
	m->size[0] = 11;
	m->size[1] = 11;
	m->pov = 0;
	if (!(m->mlx = mlx_init(WIDTH, HEIGH, "CUB3D", false)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	m->g_image = mlx_new_image(m->mlx, WIDTH, HEIGH);
	mlx_image_to_window(m->mlx, m->g_image, 0, 0);
	m->image = mlx_new_image(m->mlx, WIDTH / MIN, HEIGH / MIN);
	mlx_image_to_window(m->mlx, m->image, 0, 0);
	mlx_loop_hook(m->mlx, &hook, m);
	mlx_loop_hook(m->mlx, &player_moves, m);
	mlx_loop(m->mlx);
	return (EXIT_SUCCESS);
}
