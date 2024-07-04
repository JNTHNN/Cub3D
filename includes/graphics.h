/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:14:51 by gdelvign          #+#    #+#             */
/*   Updated: 2024/07/04 11:57:44 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

// Title of the graphic window
# define TITLE "Cub3D - By Jojo & Gigi"
# define STRIDE 0.042
# define ANGLE 0.042
# define MOUSE_SPEED 0.0015

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

/* windows.c */
int		ft_on_keydown(int keycode, t_data *data);
int		ft_on_keyup(int keycode, t_data *data);
int		ft_on_mousemove(int x, int y, t_data *data);
int		ft_on_mousedown(int button, int x, int y, t_data *data);
int		ft_on_mouseup(int button, int x, int y, t_data *data);
int		ft_close_window(t_data *data);
int		ft_play(t_data *data);
void	ft_img_pix_put(t_img *img, int x, int y, int color);
void	ft_set_black(t_data *data);
int		ft_player_moving(t_data *data);

/*  init.c  */
void	ft_init_mlx(t_data *data);

/*  settings.c  */
int     ft_mlx_settings(t_data *data);

/* textures.c */
void	ft_set_textures(t_data *data);

/* blur.c */
void	ft_apply_blur(t_img *img, int radius);

#endif