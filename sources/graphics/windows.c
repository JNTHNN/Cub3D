/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:09:26 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/27 21:28:48 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Closes the MLX window and frees all allocated resources */
int	ft_close_window(t_data *data)
{
	if (data)
	{
		if (data->img && data->img->mlx_img)
			mlx_destroy_image(data->mlx, data->img->mlx_img);
		mlx_destroy_window(data->mlx, data->win);
		//free_map(&data->map);
		free(data->mlx);
	}
	exit(EXIT_SUCCESS);
}

void	ft_img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	ft_draw_frame(t_img *img)
{
	int	i;
	int	j;

	i = WIN_HEIGHT - (WIN_HEIGHT / 5);
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
			ft_img_pix_put(img, j++, i, 0x0800A6);
		i++;
	}
}

void	ft_raycasting(t_data *data)
{
	t_player	player;
	int			x;
	double		camera;
	double		raydir_x;
	double		raydir_y;
	int			cell[2];
	double		delta[2];
	double		ray_length[2];
	int			step[2];
	int			hit;
	int			side;
	double		perp_wall_dist;
	int			line_height;
	int			drawline[2];

	player = data->map->player;

	// Pour chaque colonne de l'écran
	x = -1;
	while (++x < WIN_WIDTH)
	{
		// Calcul de la position du rayon et de sa direction
		camera = 2 * x / (double)WIN_WIDTH - 1;
		raydir_x = player.direction[X] + player.pov[X] * camera;
		raydir_y = player.direction[Y] + player.pov[Y] * camera;

		// Position du joueur dans la map (cellule ou case)
		cell[X] = (int)player.position[X];
		cell[Y] = (int)player.position[Y];

		// Calcul de la longueur du rayon de sa position actuelle jusque la prochaine ligne de grille (x et y)
		delta[X] = fabs(1 / raydir_x);
		delta[Y] = fabs(1 / raydir_y);
		
		if (raydir_x < 0)
		{
			step[X] = -1;
			ray_length[X] = (player.position[X] - cell[X]) * delta[X];
		}
		else
		{
			step[X] = 1;
			ray_length[X] = (cell[X] + 1.0 - player.position[X]) * delta[X];
		}
		if (raydir_y < 0)
		{
			step[Y] = -1;
			ray_length[Y] = (player.position[Y] - cell[Y]) * delta[Y];
		}
		else
		{
			step[Y] = 1;
			ray_length[Y] = (cell[Y] + 1.0 - player.position[Y]) * delta[Y];
		}
		// Boucle pour trouver le point d'impact avec le mur
		hit = 0;
		while (hit == 0)
		{
			// Saut vers la prochaine case de la map
			if (ray_length[X] < ray_length[Y])
			{
				ray_length[X] += delta[X];
				cell[X] += step[X];
				side = 0;
			}
			else
			{
				ray_length[Y] += delta[Y];
				cell[Y] += step[Y];
				side = 1;
			}
			// Le rayon a-t-il touché un mur ?
			if (data->mtx[cell[Y]][cell[X]] > 0)
			{
				hit = 1;
				printf("VALEUR = %i et HIT == %i\n", data->mtx[cell[Y]][cell[X]], hit);
			}
		}
		// Correction de la distance perpendiculaire pour corriger la perspective
		if (side == 0)
			perp_wall_dist = (cell[X] - player.position[X] + (1 - step[X]) / 2) / raydir_x;
		else
			perp_wall_dist = (cell[Y] - player.position[Y] + (1 - step[Y]) / 2) / raydir_y;
		// Vérification de perp_wall_dist pour éviter la division par zéro
		if (perp_wall_dist == 0)
			perp_wall_dist = 0.0001;
		// Calcul de la hauteur de la ligne a dessiner a l'ecran
		line_height = (int)(WIN_HEIGHT) / perp_wall_dist;
		 // Calcul des points de début et de fin pour dessiner la ligne
		drawline[START] = -line_height / 2 + WIN_HEIGHT / 2;
		if (drawline[START] < 0)
			drawline[START] = 0;
		drawline[END] = line_height / 2 + WIN_HEIGHT / 2;
		if (drawline[END] >= WIN_HEIGHT)
			drawline[END] = WIN_HEIGHT - 1;
		
		// Dessiner la ligne sur l'image
		printf("PLAYER POSITION [%f][%f] ORIENTATION [%c] \n AND DIRECTION [%f][%f] AND POV [%f][%f]\n", player.position[X], player.position[Y], player.orientation, player.direction[X], player.direction[Y], player.pov[x], player.pov[Y]);
		printf("RAYDIR = [%f][%f]\n", raydir_x, raydir_y);
		printf("PERP : %f\n", perp_wall_dist);
		printf("DRAWLINE[%i][%i]\n", drawline[START], drawline[END]);
		printf("cell = [%d, %d], step = [%d, %d], ray_length = [%f, %f], delta = [%f, %f]\n",
       cell[X], cell[Y], step[X], step[Y], ray_length[X], ray_length[Y], delta[X], delta[Y]);
	}
}

int	ft_create_img(t_data *data)
{
	t_img	*img;

	img = data->img;
	img->mlx_img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (img->mlx_img == NULL)
		return (EXIT_FAILURE);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
		&img->line_len, &img->endian);
	ft_draw_frame(img);
	ft_raycasting(data);
	//ft_apply_blur(img, 5);
	mlx_put_image_to_window(data->mlx, data->win, data->img->mlx_img, 0, 0);
	return (EXIT_SUCCESS);
}

int	ft_play(t_data *data)
{
	if (!data->win)
		ft_errno(WIN, data);
	if (ft_create_img(data))
		ft_errno(IMG, data);
	return (EXIT_SUCCESS);
}
