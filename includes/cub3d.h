/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:09:52 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/07 17:17:06 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "error.h"

typedef struct s_map	t_map;
typedef enum e_err_code	t_err_code;

typedef union
{
	struct
	{
		u_int8_t r;
		u_int8_t g;
		u_int8_t b;
	} s_rgb;
	u_int32_t	s_value;
} u_color;

struct	s_map
{
	// voir si on stocke ici les textures/chemin
	char	*file;
	int		fd;
	// couleur sol
	u_color	floor;
	// couleur plafond
	u_color	ceiling;
	// hauteur / ordonee / y
	int		y_size;
	// longueur / abscisse / x
	int		x_size;

};

enum e_err_code
{
	MEM = -1,
	TOO_MANY = -2,
	NO_MAP = -3,
	WRONG_EXT = -4,
	ERR_FD = -5
};



void	ft_errno(int err_code, t_map *map);

#endif