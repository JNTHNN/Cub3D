/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:09:13 by gdelvign          #+#    #+#             */
/*   Updated: 2024/07/04 15:52:05 by gdelvign         ###   ########.fr       */
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
		double old_fov_x;

		old_dir_x = player->direction[X];
		old_fov_x = player->fov[X];
		player->direction[X] = player->direction[X] * cos(angle) - player->direction[Y] * sin(angle);
		player->direction[Y] = old_dir_x * sin(angle) + player->direction[Y] * cos(angle);
		player->fov[X] = player->fov[X] * cos(angle) - player->fov[Y] * sin(angle);
		player->fov[Y] = old_fov_x * sin(angle) + player->fov[Y] * cos(angle);
}


bool	ft_check_collision(double *new_pos, t_data *data)
{
	int cell[2];

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
	return (EXIT_SUCCESS);
}

/* Handles key press events */
int	ft_on_keydown(int keycode, t_data *data)
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
int	ft_on_keyup(int keycode, t_data *data)
{
	t_player	*player;
	
	player = &data->map->player;
	if (keycode == ESC)
		ft_close_window(data);
	if (ft_is_moving_key(keycode))
	{
		if (keycode == KEY_UP)
			player->move &= ~M_UP;
		if (keycode == KEY_DOWN)
			player->move &= ~M_DOWN;
		if (keycode == KEY_LEFT)
			player->move &= ~M_LEFT;
		if (keycode == KEY_RIGHT)
			player->move &= ~M_RIGHT;
		if (keycode == ARROW_LEFT)
			player->move &= ~M_ROTATE_LEFT;
		if (keycode == ARROW_RIGHT)
			player->move &= ~M_ROTATE_RIGHT;
	}
	return (EXIT_SUCCESS);
}

bool	ft_cursor_is_in_window(int mouse_x, int mouse_y)
{
	if (mouse_x > 0 && mouse_x < WIN_WIDTH 
		&& mouse_y > 0 && mouse_y < WIN_HEIGHT)
		return (true);
	return (false);
}

/* Handles mouse events */
int	ft_on_mousemove(int x, int y, t_data *data)
{
	t_player	*player;
	double 		delta[2];
	double		old_mouse_pos[2];
	double 		old_fov_x;
	double 		old_dir_x;
	double		angle;

	if (data->left_click && ft_cursor_is_in_window(x, y))
	{
		player = &data->map->player;
		old_mouse_pos[X] = WIN_WIDTH / 2;
		old_mouse_pos[Y] = WIN_HEIGHT / 2;
		old_dir_x = player->direction[X];
		old_fov_x = player->fov[X];
		delta[X] = x - old_mouse_pos[X];
		delta[Y] = y - old_mouse_pos[Y];
		angle = delta[X] * MOUSE_SPEED;
		player->direction[X] = player->direction[X] * cos(angle) - player->direction[Y] * sin(angle);
		player->direction[Y] = old_dir_x * sin(angle) + player->direction[Y] * cos(angle);
		player->fov[X] = player->fov[X] * cos(angle) - player->fov[Y] * sin(angle);
		player->fov[Y] = old_fov_x * sin(angle) + player->fov[Y] * cos(angle);
		old_mouse_pos[X] = x;
		old_mouse_pos[Y] = y;
		mlx_mouse_move(data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	}
	return (EXIT_SUCCESS);
}

int 	ft_on_mousedown(int button, int x, int y, t_data *data)
{	
	if (button == 1 && ft_cursor_is_in_window(x, y))
	{
		data->left_click = true;
		mlx_mouse_hide();
	}
	return (EXIT_SUCCESS);
}

int 	ft_on_mouseup(int button, int x, int y, t_data *data)
{	
	if (button == 1 && ft_cursor_is_in_window(x, y))
	{
		data->left_click = false;
		mlx_mouse_show();
	}
	return (EXIT_SUCCESS);
}
