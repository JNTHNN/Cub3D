/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:09:52 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/20 15:25:32 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "error.h"
# include "utils.h"

# define FLOOR "F "
# define CEILING "C "
# define NORTH "NO "
# define SOUTH "SO "
# define WEST "WE "
# define EAST "EA "
# define NO 1
# define SO 2
# define WE 3
# define EA 4

typedef struct s_map	t_map;
typedef enum e_err_code	t_err_code;
typedef struct s_info	t_info;

typedef union
{
	u_int32_t	s_value;
	struct
	{
		u_int8_t b;
		u_int8_t g;
		u_int8_t r;
	} s_rgb;
} u_color;

struct	s_info
{
	char 	*floor;
	char	*ceiling;
	char	*texture_north;
	char	*texture_south;
	char	*texture_west;
	char	*texture_east;
};

struct	s_map
{
	// voir si on stocke ici les textures/chemin
	char	*file;
	int		fd;
	// couleur sol
	u_color	floor;
	// couleur plafond
	u_color	ceiling;
	// texture nord
	char	*texture_north; // a voir si je peux utiliser FILE
	// texture sud
	char	*texture_south; // a voir si je peux utiliser FILE
	// texture ouest
	char	*texture_west; // a voir si je peux utiliser FILE
	// texture est
	char	*texture_east; // a voir si je peux utiliser FILE
	// hauteur / ordonee / y
	int		y_size;
	// longueur / abscisse / x
	int		x_size;

};

enum e_err_code
{
	MEM = -1,
	TOO_MANY = -2,
	NO_MAP = -3,
	WRONG_EXT = -4,
	ERR_FD = -5,
	DUP_INFO = -6,
	ERR_COLOR = -7
};



void	ft_errno(int err_code, t_map *map);

#endif