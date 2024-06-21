/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:09:52 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/21 13:24:35 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "typedef.h"
# include "error.h"
# include "utils.h"
# include "controls.h"

// Title of the graphic window
# define TITLE "Cub3D - By Jojo & Gigi"

enum e_mlx_macros
{
	WIN_WIDTH = 1200,
	WIN_HEIGHT = 620,
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	ESC = 53,
};

# define FLOOR "F "
# define CEILING "C "
# define NORTH "NO "
# define SOUTH "SO "
# define WEST "WE "
# define EAST "EA "
# define NO 1
# define SO 2
# define WE 3
# define EA 4

void	ft_errno(int err_code, t_data *data);

#endif