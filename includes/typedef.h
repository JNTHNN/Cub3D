/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:19:30 by gdelvign          #+#    #+#             */
/*   Updated: 2024/07/01 14:52:18 by gdelvign         ###   ########.fr       */
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
typedef struct s_player	t_player;
typedef enum e_err_code	t_err_code;
typedef enum e_wall		t_wall;
typedef enum e_orientation	t_orientation;
typedef struct s_file	t_file;


typedef struct s_data				t_data;
typedef struct s_img				t_img;
typedef struct s_map				t_map;
typedef struct s_info				t_info;
typedef struct s_orientation_att	t_orientation_att;
typedef enum e_err_code				t_err_code;
typedef enum e_wall					t_wall;
typedef enum e_orientation			t_orientation;
typedef struct s_player				t_player;
typedef struct s_p_orientation 		t_p_orientation;
typedef struct s_orientation_att 	t_orientation_att;

enum e_orientation
{
	N = 78,
	E = 69,
	S = 83,
	W = 87,
	NONE = -1,
	UNSET = 2
};

enum e_coord
{
	Y = 0,
	X = 1
};

enum e_draw_pos
{
	START = 0,
	END = 1
};

struct s_p_orientation
{
    double dir[2];
   	double pov[2];
};

struct s_orientation_att 
{
    t_p_orientation north;
    t_p_orientation south;
    t_p_orientation east;
    t_p_orientation west;
};

struct s_player
{
	t_orientation	orientation;
	double			position[2];
	double			direction[2];
	double			pov[2];
	int				move;
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
	char		*file;
	int			fd;
	// couleur sol
	u_color		floor;
	// couleur plafond
	u_color		ceiling;
	// texture nord
	char		*texture_north; // a voir si je peux utiliser FILE
	// texture sud
	char		*texture_south; // a voir si je peux utiliser FILE
	// texture ouest
	char		*texture_west; // a voir si je peux utiliser FILE
	// texture est
	char		*texture_east; // a voir si je peux utiliser FILE
	// hauteur / ordonee / y
	int			y_size;
	// longueur / abscisse / x
	int			x_size;
	// map brute
	char	**map;
	// map spaces remplacé par 2
	char	**square_map;
	t_player	player; // TEST: position du player
};

struct s_file
{
	char	**raw_file;
	int		fd;
	int		size;
	int		start;
	int		end;
};

struct s_data
{
	void				*mlx;
	void				*win;
	t_info				*info;
	t_img				*img;
	t_map				*map;
	int					**mtx;
	int					*row_widths;
	t_file				*file;
	t_orientation_att	o_attributes;
	// Remove after test
	FILE 				*fd;
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
	MISSING = -10,
	NOT_NB = -11,
	NO_MAP_CONTENT = -12,
	MAP_NOT_CLOSE = -13,
	NO_PLAYER = -14,
	MANY_PLAYERS = -15,
	WRONG_CHAR = -16,
	AMB_PLAYER = -17
};

enum e_mlx_err_code
{
	MLX = -400,
	WIN = -401,
	IMG = -402
};

enum e_wall
{
	TOP,
	BOT,
	LEFT,
	RIGHT
};

#endif