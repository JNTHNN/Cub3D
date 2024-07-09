/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:19:30 by gdelvign          #+#    #+#             */
/*   Updated: 2024/07/09 15:53:05 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

# define FLOOR "F "
# define FLOOR_TAB "F\t"
# define CEILING "C "
# define CEILING_TAB "C\t"
# define NORTH "NO "
# define NORTH_TAB "NO\t"
# define SOUTH "SO "
# define SOUTH_TAB "SO\t"
# define WEST "WE "
# define WEST_TAB "WE\t"
# define EAST "EA "
# define EAST_TAB "EA\t"
# define NO 1
# define SO 2
# define WE 3
# define EA 4
# define WALL 49
# define GROUND 48
# define EMPTY 50
# define SPACE 32
# define FOV_0 0
# define FOV_66 0.66
# define FOV_M66 -0.66
# define DIR_0 0
# define DIR_1 1
# define DIR_M1 -1
# define OFFSET 0.5
# define TITLE "Cub3D - By Jojo & Gigi"
# define STRIDE 0.055
# define ANGLE 0.042
# define MOUSE_SPEED 0.0015

typedef enum e_wall					t_wall;
typedef enum e_orientation			t_orientation;
typedef enum e_err_code				t_err_code;
typedef union u_color				t_color;
typedef struct s_info				t_info;
typedef struct s_file				t_file;
typedef struct s_p_orientation		t_p_orientation;
typedef struct s_orientation_att	t_orientation_att;
typedef struct s_ray_c				t_ray_c;
typedef struct s_player				t_player;
typedef struct s_xpm				t_xpm;
typedef struct s_textures			t_textures;
typedef struct s_img				t_img;
typedef struct s_map				t_map;
typedef struct s_minimap			t_minimap;
typedef struct s_data				t_data;

enum e_mlx_macros
{
	WIN_WIDTH = 1280,
	WIN_HEIGHT = 720,
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	ESC = 53,
};

enum e_move_keys
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	ARROW_LEFT = 123,
	ARROW_RIGHT = 124,
	ARROW_DOWN = 125,
	ARROW_UP = 126,
};

enum e_movements
{
	M_LEFT = 1U,
	M_RIGHT = 2U,
	M_UP = 4U,
	M_DOWN = 8U,
	M_ROTATE_LEFT = 16U,
	M_ROTATE_RIGHT = 32U
};

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
	AMB_PLAYER = -17,
	MLX = -400,
	WIN = -401,
	IMG = -402,
	ADD = -403,
	OPEN = -404
};

enum e_wall
{
	TOP,
	BOT,
	LEFT,
	RIGHT
};

union u_color
{
	u_int32_t	s_value;
	struct
	{
		u_int8_t	b;
		u_int8_t	g;
		u_int8_t	r;
	} s_rgb;
};

struct	s_info
{
	char	*floor;
	char	*ceiling;
	char	*texture_north;
	char	*texture_south;
	char	*texture_west;
	char	*texture_east;
};

struct s_file
{
	char	**raw_file;
	int		fd;
	int		size;
	int		start;
	int		end;
};

struct s_p_orientation
{
	double	dir[2];
	double	fov[2];
};

struct s_orientation_att
{
	t_p_orientation	north;
	t_p_orientation	south;
	t_p_orientation	east;
	t_p_orientation	west;
};

struct s_player
{
	t_orientation	orientation;
	double			position[2];
	double			direction[2];
	double			fov[2];
	int				move;
};

struct s_xpm
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
};

struct s_textures
{
	t_xpm	*tex_north;
	t_xpm	*tex_south;
	t_xpm	*tex_east;
	t_xpm	*tex_west;
};

struct s_ray_c
{
	int		x;
	double	camera;
	double	raydir_x;
	double	raydir_y;
	int		cell[2];
	double	delta[2];
	double	ray_length[2];
	int		step[2];
	int		hit;
	int		side;
	double	perp_dist;
	int		line_height;
	int		drawline[2];
	t_xpm	*texture;
	int		tex_x;
	double	tex_step;
	double	tex_pos;
	int		tex_color;
	double	impact;
};

struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
};

struct	s_map
{
	char		*file;
	int			fd;
	t_color		floor;
	t_color		ceiling;
	char		*texture_north;
	char		*texture_south;
	char		*texture_west;
	char		*texture_east;
	int			y_size;
	int			x_size;
	char		**map;
	char		**square_map;
	t_player	player;
};

struct	s_minimap
{
	t_img	*img;
	int		width;
	int		height;
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
	t_textures			*textures;
	bool				left_click;
	t_minimap			*minimap;
};

#endif