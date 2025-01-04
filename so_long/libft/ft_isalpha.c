/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:10:52 by bsoykan           #+#    #+#             */
/*   Updated: 2023/12/07 18:10:53 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int str)
{
	if ((str >= 65 && str <= 90) || (str >= 97 && str <= 122))
		return (1);
	else
		return (0);
}
