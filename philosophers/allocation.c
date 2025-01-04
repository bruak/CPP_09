/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:59:54 by bsoykan           #+#    #+#             */
/*   Updated: 2024/01/22 16:54:51 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "stdlib.h"
#include "unistd.h"

int	allocation(t_data *table_datas)
{
	int		i;

	i = -1;
	table_datas->forks
		= (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* table_datas->number_of_philo);
	if (!table_datas->forks)
		return (write(2, ALOCK_ERR, 25), SUCCESS_RETURN);
	table_datas->philos = (t_philo *)malloc(sizeof(t_philo)
			* table_datas->number_of_philo);
	if (!table_datas->philos)
	{
		free(table_datas->forks);
		return (write(2, ALOCK_ERR, 25), SUCCESS_RETURN);
	}
	while (++i < table_datas->number_of_philo)
		if (pthread_mutex_init(&table_datas->forks[i], NULL))
			return (write(2, MTX_ERR, 25), mutex_destroy(table_datas, ALL),
				SUCCESS_RETURN);
	return (ZERO_RETURN);
}
