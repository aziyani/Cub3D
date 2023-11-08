/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:10:27 by aziyani           #+#    #+#             */
/*   Updated: 2023/11/02 12:01:16 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include <fcntl.h>

# include <stdio.h>
#include <stdbool.h>


typedef struct s_data
{
	char	**map_db;
	
	char	*texture1;
	char	*texture2;
	char	*texture3;
	char	*texture4;
	char	*av;

	int		sky[3];
	int		floor[3];
	
}t_data;

typedef struct s_check {
	int	no;
	int	we;
	int	ea;
	int	so;
	int	c;
	int	f;
}		t_check;

#endif