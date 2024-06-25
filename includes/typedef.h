/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:19:30 by gdelvign          #+#    #+#             */
/*   Updated: 2024/06/25 11:26:05 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

# define WALL 49
# define GROUND 48
# define EMPTY 50
# define SPACE 32

# include <stdio.h>

typedef struct s_data	t_data;
typedef struct s_img	t_img;
typedef struct s_map	t_map;
typedef struct s_info	t_info;
typedef enum e_err_code	t_err_code;
typedef enum e_wall		t_wall;
typedef enum e_position	t_position;

enum e_position
{
	N = 78,
	E = 69,
	S = 83,
	W = 87,
	NONE = -1
};

struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
};

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
	// map brute
	char	**map;
	int		start;
	t_position	player; // TEST: position du player
};

struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	map;
};

enum e_err_code
{
	MEM = -1,
	TOO_MANY = -2,
	NO_MAP = -3,
	WRONG_EXT = -4,
	ERR_FD = -5,
	DUP_INFO = -6,
	ERR_COLOR = -7,
	MLX = -8,
	WIN = -9,
	MISSING = -10,
	NOT_NB = -11,
	NO_MAP_CONTENT = -12,
	MAP_NOT_CLOSE = -13,
	NO_PLAYER = -14,
	MANY_PLAYERS = -15,
	WRONG_CHAR = -16
};

enum e_wall
{
	TOP,
	BOT,
	LEFT,
	RIGHT
};

#endif