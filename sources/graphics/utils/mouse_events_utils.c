/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:48:04 by gdelvign          #+#    #+#             */
/*   Updated: 2024/07/05 22:09:15 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_cursor_is_in_window(int mouse_x, int mouse_y)
{
	if (mouse_x > 0 && mouse_x < WIN_WIDTH
		&& mouse_y > 0 && mouse_y < WIN_HEIGHT)
		return (true);
	return (false);
}

void	ft_update_player_pos_fov(double angle,
	double old_dir_x, double old_fov_x, t_data *data)
{
	t_player	*player;

	player = &data->map->player;
	player->direction[X] = player->direction[X] * cos(angle)
		- player->direction[Y] * sin(angle);
	player->direction[Y] = old_dir_x * sin(angle)
		+ player->direction[Y] * cos(angle);
	player->fov[X] = player->fov[X] * cos(angle) - player->fov[Y] * sin(angle);
	player->fov[Y] = old_fov_x * sin(angle) + player->fov[Y] * cos(angle);
}
