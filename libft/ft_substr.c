/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:35:27 by gdelvign          #+#    #+#             */
/*   Updated: 2024/01/16 10:23:11 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substr;
	size_t		i;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		substr = (char *) malloc(sizeof(char));
	else if (ft_strlen(s) - start > len)
		substr = (char *) malloc((len + 1) * sizeof(char));
	else
		substr = (char *) malloc((ft_strlen(s) - start + 1) * sizeof(char));
	if (!substr)
		return (0);
	i = 0;
	while (i < len && start < ft_strlen(s))
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
