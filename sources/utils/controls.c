/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:09:13 by gdelvign          #+#    #+#             */
/*   Updated: 2024/06/21 14:54:06 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Handles key press events */
int	ft_handle_key_events(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_close_window(data);
	return (EXIT_SUCCESS);
}

/* Handles mouse events */
int	ft_handle_mouse_events(int button, int x, int y, t_data *data)
{
	// dumb code to silence compilation warnings
	(void)x;
	(void)y;
	if (data && button == 5)
		return (5);
	return (EXIT_SUCCESS);
}

/* Closes the MLX window and frees all allocated resources */
int	ft_close_window(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img->mlx_img);
	mlx_destroy_window(data->mlx, data->win);
	//free_map(&data->map);
	free(data->mlx);
	exit(EXIT_SUCCESS);
}

int	ft_play(t_data *data)
{
	if (!data->win)
		ft_errno(WIN, data);
	//map_to_img(data, &data->map);
	//mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
	return (EXIT_SUCCESS);
}