/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:45:35 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/26 11:36:55 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	ft_check_arg(argc, argv);
	data = ft_init_data(MAP);
	// now le fichier cub est bon
	ft_setup_map(data);
	ft_init_mlx(data);
	ft_mlx_settings(data);
	return (EXIT_SUCCESS);
}

// pour la longueur -> calculer chaque ligne avec un buff qui sauve la +longue et change si >*