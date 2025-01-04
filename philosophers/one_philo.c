/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:16:11 by bsoykan           #+#    #+#             */
/*   Updated: 2024/01/28 15:41:37 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

void	*one_philo(void *ptr)
{
	t_philo			*philosopher;

	philosopher = (t_philo *)ptr;
	printf(" %lld %d %s \n", hell_time() - philosopher->data->beginning_time,
		philosopher->data->number_of_philo, TAKE_FORK);
	sleep_implement(philosopher->data->death_duration);
	printf(" %lld %d %s", hell_time() - philosopher->data->beginning_time,
		philosopher->data->number_of_philo, KILL);
	return (NULL);
}

int	if_one_philo(t_data *table_datas)
{
	table_datas->beginning_time = hell_time();
	if (pthread_create(&table_datas->philos[0].p_thread, NULL,
			&one_philo, &table_datas->philos[0]) != 0)
		return (write(2, THREAD_CREATE_ERR, 28), SUCCESS_RETURN);
	if (pthread_join(table_datas->philos[0].p_thread, NULL))
		return (write(2, THREAD_JOIN_ERR, 26), SUCCESS_RETURN);
	return (SUCCESS_RETURN);
}
