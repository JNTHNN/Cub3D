/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:45:35 by jgasparo          #+#    #+#             */
/*   Updated: 2024/07/04 17:06:56 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Check if file extension is .cub
*/
static void	ft_check_arg(int argc, char **argv)
{
	char	*file_extension;

	if (argc > 2)
		ft_errno(TOO_MANY, NULL);
	else if (argc < 2)
		ft_errno(NO_MAP, NULL);
	else
	{
		file_extension = ft_strrchr(argv[1], DOT);
		if (!file_extension
			|| (ft_strlen(file_extension) != 4
				|| ft_strncmp(file_extension, CUB, ft_strlen(CUB))))
			ft_errno(WRONG_EXT, NULL);
	}
}

static t_data	*ft_init_data(char *file)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		ft_errno(MEM, data);
	data->mlx = NULL;
	data->win = NULL;
	data->img = (t_img *)malloc(sizeof(t_img));
	if (!data->img)
		ft_errno(MEM, data);
	data->img = ft_memset(data->img, 0, sizeof(t_img));
	data->map = ft_init_map(data, file);
	data->info = ft_init_info(data);
	data->file = ft_init_file(data);
	data->o_attributes = ft_init_o_attributes();
	data->textures = ft_init_textures(data);
	data->left_click = false;
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	ft_check_arg(argc, argv);
	data = ft_init_data(argv[1]);
	ft_setup_map(data);
	ft_init_mlx(data);
	ft_mlx_settings(data);
	return (EXIT_SUCCESS);
}
