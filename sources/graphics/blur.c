/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blur.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:48:43 by gdelvign          #+#    #+#             */
/*   Updated: 2024/07/08 18:14:50 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_img_pix_get(t_img *img, int x, int y)
{
	char	*pixel;
	int		color;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	color = *(unsigned int *)pixel;
	return (color);
}

void	ft_apply_blur(t_data *data, int radius)
{
int		x, y, i, j;
	int		r, g, b, count;
	int		color;
	int		new_color;
	t_img	tmp_img;

	// Créer une copie de l'image
	tmp_img.mlx_img = mlx_new_image(data->img->mlx_img, WIN_WIDTH, WIN_HEIGHT);
	tmp_img.addr = mlx_get_data_addr(tmp_img.mlx_img, &tmp_img.bpp, &tmp_img.line_len, &tmp_img.endian);

	// Appliquer le flou
	for (y = 0; y < WIN_HEIGHT; y++)
	{
		for (x = 0; x < WIN_WIDTH; x++)
		{
			r = g = b = count = 0;
			for (j = -radius; j <= radius; j++)
			{
				for (i = -radius; i <= radius; i++)
				{
					if (x + i >= 0 && x + i < WIN_WIDTH && y + j >= 0 && y + j < WIN_HEIGHT)
					{
						color = ft_img_pix_get(data->img, x + i, y + j);
						r += (color >> 16) & 0xFF;
						g += (color >> 8) & 0xFF;
						b += color & 0xFF;
						count++;
					}
				}
			}
			if (count > 0)
			{
				r /= count;
				g /= count;
				b /= count;
				new_color = (r << 16) | (g << 8) | b;
				ft_img_pix_put(&tmp_img, x, y, new_color);
			}
		}
	}

	// Copier les pixels floutés dans l'image originale
	ft_memcpy(data->img->addr, tmp_img.addr, WIN_WIDTH * WIN_HEIGHT * (data->img->bpp / 8));

	// Libérer l'image temporaire
	mlx_destroy_image(data->mlx, tmp_img.mlx_img);

}
