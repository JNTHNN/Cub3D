/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:14:51 by gdelvign          #+#    #+#             */
/*   Updated: 2024/06/26 16:56:10 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

// Title of the graphic window
# define TITLE "Cub3D - By Jojo & Gigi"

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

enum e_movements
{
	M_UP = 13,
	M_DOWN = 1,
	M_LEFT = 0,
	M_RIGHT = 2
};

/* windows.c */
int	    ft_handle_key_events(int keycode, t_data *data);
int	    ft_handle_mouse_events(int button, int x, int y, t_data *data);
int	    ft_close_window(t_data *data);
int	    ft_play(t_data *data);
void	ft_img_pix_put(t_img *img, int x, int y, int color);
void	ft_set_black(t_data *data);

/*  init.c  */
void	ft_init_mlx(t_data *data);

/*  settings.c  */
int     ft_mlx_settings(t_data *data);

/* blur.c */
void	ft_apply_blur(t_img *img, int radius);

#endif