/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:09:13 by gdelvign          #+#    #+#             */
/*   Updated: 2024/07/01 17:01:12 by gdelvign         ###   ########.fr       */
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

// bool	ft_validate_new_position(double new_x, double new_y)


int ft_player_moving(t_data *data)
{
	t_player	*player;
	
	player = &data->map->player;
	
	if ((player->move & M_UP) != 0)
	{
		player->position[Y] += player->direction[Y] * 0.069;
		player->position[X] += player->direction[X] * 0.069;
	}
	if ((player->move & M_DOWN) != 0)
	{
		player->position[Y] -= player->direction[Y] * 0.069;
		player->position[X] -= player->direction[X] * 0.069;
	}
	if ((player->move & M_LEFT) != 0)
	{
		player->position[X] += player->direction[Y] * 0.069;
		player->position[Y] -= player->direction[X] * 0.069;
	}
	if ((player->move & M_RIGHT) != 0)
	{
		player->position[X] -= player->direction[Y] * 0.069;
		player->position[Y] += player->direction[X] * 0.069;
	}

	if (player->position[X] < 1)
		player->position[X] = 1.150;
	if (player->position[X] > (data->map->x_size - 1))
		player->position[X] = data->map->x_size - 1.150;
	if (player->position[Y] < 1)
		player->position[Y] = 1.150;
	if (player->position[Y] > (data->map->y_size - 1))
		player->position[Y] = data->map->y_size - 1.150;
	printf("MAP x, y = [%i] [%i]", data->map->x_size, data->map->y_size);
	printf("PLAYER POSITION X,Y = [%f][%f]\n", player->position[X], player->position[Y]);
	return (EXIT_SUCCESS);
}


// PAYER MOVE

/* Handles key press events */
int	ft_handle_keydown_events(int keycode, t_data *data)
{
	t_player	*player;
	
	player = &data->map->player;
	if (keycode == ESC)
		ft_close_window(data);
	if (ft_is_moving_key(keycode))
	{
		if (keycode == KEY_UP || keycode == ARROW_UP)
			player->move |= M_UP;
		else if (keycode == KEY_DOWN || keycode == ARROW_DOWN)
			player->move |= M_DOWN;
		else if (keycode == KEY_LEFT)
			player->move |= M_LEFT;
		else if (keycode == KEY_RIGHT)
			player->move |= M_RIGHT;
		printf("MOVE = %i \n", player->move);
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
		if (keycode == KEY_UP || keycode == ARROW_UP)
			player->move &= ~M_UP;
		else if (keycode == KEY_DOWN || keycode == ARROW_DOWN)
			player->move &= ~M_DOWN;
		else if (keycode == KEY_LEFT)
			player->move &= ~M_LEFT;
		else if (keycode == KEY_RIGHT)
			player->move &= ~M_RIGHT;
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
