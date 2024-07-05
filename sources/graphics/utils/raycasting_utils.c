/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:42:15 by gdelvign          #+#    #+#             */
/*   Updated: 2024/07/05 17:00:48 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_get_ray_length_to_next_cell(t_ray_c *rc, t_player player)
{
	if (rc->raydir_x < 0)
	{
		rc->step[X] = -1;
		rc->ray_length[X] = (player.position[X] - rc->cell[X]) * rc->delta[X];
	}
	else
	{
		rc->step[X] = 1;
		rc->ray_length[X] = (rc->cell[X] + 1.0
				- player.position[X]) * rc->delta[X];
	}
	if (rc->raydir_y < 0)
	{
		rc->step[Y] = -1;
		rc->ray_length[Y] = (player.position[Y] - rc->cell[Y]) * rc->delta[Y];
	}
	else
	{
		rc->step[Y] = 1;
		rc->ray_length[Y] = (rc->cell[Y] + 1.0
				- player.position[Y]) * rc->delta[Y];
	}
}

void	ft_set_rc_vars(t_ray_c *rc, t_player player)
{
	rc->camera = 2 * rc->x / (double)WIN_WIDTH - 1;
	rc->raydir_x = player.direction[X] + player.fov[X] * rc->camera;
	rc->raydir_y = player.direction[Y] + player.fov[Y] * rc->camera;
	rc->cell[X] = (int)player.position[X];
	rc->cell[Y] = (int)player.position[Y];
	rc->delta[X] = fabs(1 / rc->raydir_x);
	rc->delta[Y] = fabs(1 / rc->raydir_y);
	rc->hit = 0;
	ft_get_ray_length_to_next_cell(rc, player);
}

void	ft_get_point_of_impact(t_ray_c *rc, t_data *data)
{
	while (rc->hit == 0)
	{
		if (rc->ray_length[X] < rc->ray_length[Y])
		{
			rc->ray_length[X] += rc->delta[X];
			rc->cell[X] += rc->step[X];
			rc->side = 0;
		}
		else
		{
			rc->ray_length[Y] += rc->delta[Y];
			rc->cell[Y] += rc->step[Y];
			rc->side = 1;
		}
		if (data->mtx[rc->cell[Y]][rc->cell[X]] > 0)
			rc->hit = 1;
	}
}
