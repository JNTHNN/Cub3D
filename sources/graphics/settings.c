/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:10:03 by jgasparo          #+#    #+#             */
/*   Updated: 2024/07/08 14:04:51 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Closes the MLX window and frees all allocated resources */
int	ft_close_window(t_data *data)
{
	ft_free_data(data);
	exit(EXIT_SUCCESS);
}

static int	ft_create_img(t_data *data)
{
	t_img	*img;

	img = data->img;
	img->mlx_img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (img->mlx_img == NULL)
		return (EXIT_FAILURE);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
			&img->line_len, &img->endian);
	ft_move_player(data);
	ft_draw_background(img, data->map);
	ft_raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, img->mlx_img, 0, 0);
	mlx_destroy_image(data->mlx, data->img->mlx_img);
	data->img->mlx_img = NULL;
	return (EXIT_SUCCESS);
}

static int	ft_play(t_data *data)
{
	if (!data->win)
		ft_error(WIN, STR_ERR_WIN, data);
	if (ft_create_img(data))
		ft_error(IMG, STR_ERR_IMG, data);
	return (EXIT_SUCCESS);
}

int	ft_mlx_settings(t_data *data)
{
	mlx_hook(data->win, ON_KEYDOWN, 0, ft_on_keydown, data);
	mlx_hook(data->win, ON_KEYUP, 0, ft_on_keyup, data);
	mlx_hook(data->win, ON_MOUSEMOVE, 0, ft_on_mousemove, data);
	mlx_hook(data->win, ON_MOUSEDOWN, 0, ft_on_mousedown, data);
	mlx_hook(data->win, ON_MOUSEUP, 0, ft_on_mouseup, data);
	mlx_hook(data->win, ON_DESTROY, 0, ft_close_window, data);
	if (mlx_loop_hook(data->mlx, &ft_play, data))
		return (ft_close_window(data));
	mlx_loop(data->mlx);
	return (EXIT_SUCCESS);
}
