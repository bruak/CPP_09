/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:38:55 by bsoykan           #+#    #+#             */
/*   Updated: 2023/07/10 15:45:29 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str[0] && !c)
		return ((char *) str);
	while (str[i])
	{
		if (str[i] == (unsigned char) c)
			return ((char *) str + i);
		i++;
	}
	if ((unsigned char) c)
		return (NULL);
	return ((char *) str + i);
}
