/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:07:38 by jgasparo          #+#    #+#             */
/*   Updated: 2024/07/01 11:42:42 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define STR_ERR_MLX "Error\nUnable to initialize graphics. Please try again."
# define STR_ERR_WIN "Error\nUnable to open graphic window. Please try again."
# define STR_ERR_IMG "Error\nCouldn't renderer the image."

# define STR_MEM "Error\nMemory allocation goes wrong"
# define STR_TOO_MANY "Error\nToo many arguments"
# define STR_NO_MAP	"Error\nNo Map, No Game"
# define STR_WRONG_EXT "Error\nWrong file extension"
# define STR_DUP_INFO "Error\nDuplicate info in map"
# define STR_ERR_COLOR "Error\nWrong color's value"
# define STR_MISSING "Error\nMissing data"
# define STR_NOT_NB "Error\nNot a number in color"
# define STR_NO_MAP_CONTENT "Error\nNo Map Content, No Party"
# define STR_MAP_NOT_CLOSE "Error\nMap not closed/surronded by walls"
# define STR_NO_PLAYER "Error\nNo player in the map, omagad"
# define STR_MANY_PLAYERS "Error\nStay cool, too many players in ze map"
# define STR_WRONG_CHAR "Error\nForbidden character in ze map, mayday mayday"
# define STR_AMB_PLAYER "Error\nAmbigious player's position. Please try again"
# define CUB ".cub"
# define DOT 46
# define MAP argv[1]

/*	error.c	*/
void	ft_check_arg(int argc, char **argv);

#endif