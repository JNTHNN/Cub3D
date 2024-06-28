/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:09:13 by gdelvign          #+#    #+#             */
/*   Updated: 2024/06/28 22:42:25 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Checks if the key pressed is for a player movement : W, A, S, D. */
bool	ft_is_moving_key(int keycode)
{
	if (keycode == M_UP || (keycode >= M_LEFT && keycode <= M_RIGHT))
		return (true);
	return (false);
}

/* Handles key press events */
int	ft_handle_key_events(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_close_window(data);
	if (ft_is_moving_key(keycode))
	{
		// Function for movements handling here.
		printf("KEYCODE = %i OK\n", keycode);
		if (keycode == M_UP)
		{
			data->map->player.position[Y] += data->map->player.direction[Y];
			data->map->player.position[X] += data->map->player.direction[X];
			ft_set_black(data);
			if (mlx_loop_hook(data->mlx, &ft_play, data))
				return (ft_close_window(data));
		}
		if (keycode == M_DOWN)
		{
			data->map->player.position[Y] -= data->map->player.direction[Y];
			data->map->player.position[X] -= data->map->player.direction[X];
			ft_set_black(data);
			if (mlx_loop_hook(data->mlx, &ft_play, data))
				return (ft_close_window(data));
		}
		if (keycode == M_LEFT)
		{
			data->map->player.position[X] += data->map->player.direction[Y];
			data->map->player.position[Y] -= data->map->player.direction[X];
			ft_set_black(data);
			if (mlx_loop_hook(data->mlx, &ft_play, data))
				return (ft_close_window(data));
		}
			if (keycode == M_RIGHT)
		{
			data->map->player.position[X] -= data->map->player.direction[Y];
			data->map->player.position[Y] += data->map->player.direction[X];
			
			ft_set_black(data);
			if (mlx_loop_hook(data->mlx, &ft_play, data))
				return (ft_close_window(data));
		}
	}
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
