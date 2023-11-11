/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CUB3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:10:27 by aziyani           #+#    #+#             */
/*   Updated: 2023/11/11 16:08:16 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "parsing/gnl/get_next_line.h"
#include "parsing/lbft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdbool.h>
#include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
#include <stdbool.h>

#define CUB_SIZE 50
#define WIDTH 1080
#define HEIGH 900
#define MIN 2
#define W_COLOR 0x960F18FF
#define G_COLOR 0XB9B3B3FF
#define P_COLOR 0x114E61FF
#define RAD 0.0174532925

typedef struct s_point
{
	float x;
	float y;
} t_point;

typedef struct
{
	char		**map_db;
	char		**map;
	char		*av;
	int			sky[3];
	int			floor[3];
	int32_t		*size;
	float		distance;
	float		goal_x;
	float		goal_y;
	float		ofo9i_x;
	float		ofo9i_y;
	float		amodi_x;
	float		amodi_y;
	float		s_x;
	float		s_y;
	float		pov;
    mlx_t*		mlx;
    mlx_image_t *image;
    mlx_image_t *g_image;
} s_main;


typedef struct s_check {
	int	no;
	int	we;
	int	ea;
	int	so;
	int	c;
	int	f;
}		t_check;


int start_game(s_main *m);



/*----------------------------PARCING-------------------------------*/
void	check_ceil(char *s, s_main *cub);
void	check_news(s_main *m, int i);
void	check_map(s_main *m, int i);
void	ft_errorr(char *s);


int	check_floor(char *s, s_main *cub);
int	skip_spaces(char *s, int index);
int	check_path(char **s, int ch);
int	check_path(char **s, int ch);
int	count_map_lines(int fd);
int	ft_count(char	*s1);

char	*skip_s(char *s);

t_check	initialize_check(void);


#endif
