/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:29:00 by gdelvign          #+#    #+#             */
/*   Updated: 2024/07/05 22:23:13 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_rotate_player(t_player *player, double angle)
{
	double	old_dir_x;
	double	old_fov_x;

	old_dir_x = player->direction[X];
	old_fov_x = player->fov[X];
	player->direction[X] = player->direction[X] * cos(angle)
		- player->direction[Y] * sin(angle);
	player->direction[Y] = old_dir_x * sin(angle)
		+ player->direction[Y] * cos(angle);
	player->fov[X] = player->fov[X] * cos(angle) - player->fov[Y] * sin(angle);
	player->fov[Y] = old_fov_x * sin(angle) + player->fov[Y] * cos(angle);
}

static bool	ft_check_collision(double *new_pos, t_data *data)
{
	int	cell[2];

	cell[X] = (int)new_pos[X];
	cell[Y] = (int)new_pos[Y];
	if (cell[Y] < 1 || cell[Y] >= data->map->y_size - 1)
		return (true);
	if (cell[X] < 1 || cell[X] >= data->map->x_size - 1)
		return (true);
	if (data->mtx[cell[Y]][cell[X]] == 1)
		return (true);
	return (false);
}

static void	ft_calculate_new_pos(double new_pos[2], t_player *player)
{
	if ((player->move & M_UP) != 0)
	{
		new_pos[Y] = player->position[Y] + player->direction[Y] * STRIDE;
		new_pos[X] = player->position[X] + player->direction[X] * STRIDE;
	}
	if ((player->move & M_DOWN) != 0)
	{
		new_pos[Y] = player->position[Y] - player->direction[Y] * STRIDE;
		new_pos[X] = player->position[X] - player->direction[X] * STRIDE;
	}
	if ((player->move & M_LEFT) != 0)
	{
		new_pos[X] = player->position[X] + player->direction[Y] * STRIDE;
		new_pos[Y] = player->position[Y] - player->direction[X] * STRIDE;
	}
	if ((player->move & M_RIGHT) != 0)
	{
		new_pos[X] = player->position[X] - player->direction[Y] * STRIDE;
		new_pos[Y] = player->position[Y] + player->direction[X] * STRIDE;
	}
}

int	ft_move_player(t_data *data)
{
	t_player	*player;
	double		new_pos[2];

	player = &data->map->player;
	ft_calculate_new_pos(new_pos, player);
	if ((player->move & M_ROTATE_LEFT) != 0)
		ft_rotate_player(player, -ANGLE);
	if ((player->move & M_ROTATE_RIGHT) != 0)
		ft_rotate_player(player, ANGLE);
	if (!ft_check_collision(new_pos, data))
	{
		player->position[Y] = new_pos[Y];
		player->position[X] = new_pos[X];
	}
	return (EXIT_SUCCESS);
}
