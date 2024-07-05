/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:42:34 by gdelvign          #+#    #+#             */
/*   Updated: 2024/07/05 22:33:26 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_on_mousemove(int x, int y, t_data *data)
{
	double		delta[2];
	double		old_mouse_pos[2];
	double		old_fov_x;
	double		old_dir_x;
	double		angle;

	if (data->left_click && ft_cursor_is_in_window(x, y))
	{
		old_mouse_pos[X] = WIN_WIDTH / 2;
		old_mouse_pos[Y] = WIN_HEIGHT / 2;
		old_dir_x = data->map->player.direction[X];
		old_fov_x = data->map->player.fov[X];
		delta[X] = x - old_mouse_pos[X];
		delta[Y] = y - old_mouse_pos[Y];
		angle = delta[X] * MOUSE_SPEED;
		ft_update_player_pos_fov(angle, old_dir_x, old_fov_x, data);
		old_mouse_pos[X] = x;
		old_mouse_pos[Y] = y;
		mlx_mouse_move(data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	}
	return (EXIT_SUCCESS);
}

int	ft_on_mousedown(int button, int x, int y, t_data *data)
{
	if (button == 1 && ft_cursor_is_in_window(x, y))
	{
		data->left_click = true;
		mlx_mouse_hide();
	}
	return (EXIT_SUCCESS);
}

int	ft_on_mouseup(int button, int x, int y, t_data *data)
{
	if (button == 1 && ft_cursor_is_in_window(x, y))
	{
		data->left_click = false;
		mlx_mouse_show();
	}
	return (EXIT_SUCCESS);
}
