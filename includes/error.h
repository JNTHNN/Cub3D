/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:07:38 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/22 20:24:47 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define STR_MEM "Error\nMemory allocation goes wrong"
# define STR_TOO_MANY "Error\nToo many arguments"
# define STR_NO_MAP	"Error\nNo Map, No Game"
# define STR_WRONG_EXT "Error\nWrong file extension"
# define STR_DUP_INFO "Error\nDuplicate info in map"
# define STR_ERR_COLOR "Error\nWrong color's value"
# define STR_ERR_MLX "Error\nUnable to initialize graphics. Please try again."
# define STR_ERR_WIN "Error\nUnable to open graphic window. Please try again."
# define STR_MISSING "Error\nMissing data"
# define STR_NOT_NB "Error\nNot a number in color"
# define CUB ".cub"
# define DOT 46
# define MAP argv[1]

/*	error.c	*/
void	ft_check_arg(int argc, char **argv);

#endif