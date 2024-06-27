/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:09:26 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/26 17:00:44 by gdelvign         ###   ########.fr       */
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
    char    *pixel;
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
	int i;
	int j;

	i = WIN_HEIGHT - (WIN_HEIGHT / 5);
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
			ft_img_pix_put(img, j++, i, 0x0800A6);
		i++;
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
