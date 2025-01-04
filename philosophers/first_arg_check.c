/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_arg_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:16:11 by bsoykan           #+#    #+#             */
/*   Updated: 2024/01/28 15:41:37 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

#define TWO_HUNDRED 200
#define ZERO '0'
#define NINE '9'
#define TEN 10
#define ONE 1

int	convert_string_to_int(char *str, int i, int result)
{
	while (str[i] >= ZERO && str[i] <= NINE)
	{
		result = result * TEN + str[i] - ZERO;
		i++;
	}
	return (result);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if ((str[i] < ZERO || str[i] > NINE))
			return ((result = FAIL_RETURN), result);
		i++;
	}
	i = 0;
	result = convert_string_to_int(str, i, result);
	return (result);
}

int	first_arg_checker(char **av, t_data *table_datas)
{
	table_datas->number_of_philo = ft_atoi(av[1]);
	if (table_datas->number_of_philo < ONE
		|| table_datas->number_of_philo > TWO_HUNDRED)
		return (write(2, ARG_POZIT_ERR, 37), SUCCESS_RETURN);
	return (0);
}
