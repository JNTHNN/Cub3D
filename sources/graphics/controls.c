/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:09:13 by gdelvign          #+#    #+#             */
/*   Updated: 2024/07/01 20:30:10 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Checks if the key pressed is for a player movement : W, A, S, D. */
bool	ft_is_moving_key(int keycode)
{
	if (keycode == KEY_UP 
		|| (keycode >= KEY_LEFT && keycode <= KEY_RIGHT)
		|| (keycode >= ARROW_LEFT && keycode <= ARROW_UP)) 
		return (true);
	return (false);
}

void ft_rotate_player(t_player *player, double angle)
{
		double old_dir_x;
		double old_pov_x;
		double cos_angle;
		double sin_angle;

		old_dir_x = player->direction[X];
		old_pov_x = player->pov[X];
		cos_angle = cos(angle);
		sin_angle = sin(angle);
		player->direction[X] = player->direction[X] * cos_angle - player->direction[Y] * sin_angle;
		player->direction[Y] = old_dir_x * sin_angle + player->direction[Y] * cos_angle;
		player->pov[X] = player->pov[X] * cos_angle - player->pov[Y] * sin_angle;
		player->pov[Y] = old_pov_x * sin_angle + player->pov[Y] * cos_angle;
}


bool	ft_check_collision(double *new_pos, t_data *data)
{
	int cell[2];
	int	x_width;

	cell[X] = (int)new_pos[X];
	cell[Y] = (int)new_pos[Y];
	if (cell[Y] < 1 || cell[Y] >= data->map->y_size - 1)
		return (true);
	x_width = data->row_widths[cell[Y]];
	if (cell[X] < 1 || cell[X] >= x_width - 1)
        return (true);
	if (data->mtx[cell[Y]][cell[X]] == 1)
		return (true);
	return (false);
}

int ft_player_moving(t_data *data)
{
	t_player	*player;
	double		new_pos[2];
	
	player = &data->map->player;
	
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
	if ((player->move & M_ROTATE_LEFT) != 0)
		ft_rotate_player(player, -ANGLE);
	if ((player->move & M_ROTATE_RIGHT) != 0)
		ft_rotate_player(player, ANGLE);
	if (!ft_check_collision(new_pos, data))
	{
		player->position[Y] = new_pos[Y];
		player->position[X] = new_pos[X];
	}
	printf("PLAYER POSITION (X,Y) = [%f][%f]\n", player->position[X], player->position[Y]);
	return (EXIT_SUCCESS);
}

/* Handles key press events */
int	ft_handle_keydown_events(int keycode, t_data *data)
{
	t_player	*player;
	
	player = &data->map->player;
	if (keycode == ESC)
		ft_close_window(data);
	if (ft_is_moving_key(keycode))
	{
		if (keycode == KEY_UP)
			player->move |= M_UP;
		if (keycode == KEY_DOWN)
			player->move |= M_DOWN;
		if (keycode == KEY_LEFT)
			player->move |= M_LEFT;
		if (keycode == KEY_RIGHT)
			player->move |= M_RIGHT;
		if (keycode == ARROW_LEFT)
			player->move |= M_ROTATE_LEFT;
		if (keycode == ARROW_RIGHT)
			player->move |= M_ROTATE_RIGHT;
		ft_player_moving(data);
	}
	return (EXIT_SUCCESS);
}

/* Handles key release events */
int	ft_handle_keyup_events(int keycode, t_data *data)
{
	t_player	*player;
	
	player = &data->map->player;
	if (keycode == ESC)
		ft_close_window(data);
	if (ft_is_moving_key(keycode))
	{
		if (keycode == KEY_UP)
			player->move &= ~M_UP;
		else if (keycode == KEY_DOWN)
			player->move &= ~M_DOWN;
		else if (keycode == KEY_LEFT)
			player->move &= ~M_LEFT;
		else if (keycode == KEY_RIGHT)
			player->move &= ~M_RIGHT;
		if (keycode == ARROW_LEFT)
			player->move &= ~M_ROTATE_LEFT;
		if (keycode == ARROW_RIGHT)
			player->move &= ~M_ROTATE_RIGHT;
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
