/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:59:54 by bsoykan           #+#    #+#             */
/*   Updated: 2024/01/22 16:54:51 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define INT_MAX 2147483647

#include "philo.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	start_algorithm(t_data *data, int *i)
{
	*i = -1;
	while (++*i < data->number_of_philo)
		if (pthread_create(&data->philos[*i].p_thread, NULL,
				philosopher_routine, &data->philos[*i]))
			return (write(2, THREAD_CREATE_ERR, 28), SUCCESS_RETURN);
	*i = -1;
	return (ZERO_RETURN);
}

void	join_function(t_data *table_datas, int *i)
{
	*i = -1;
	while (++*i < table_datas->number_of_philo)
		if (pthread_join(table_datas->philos[*i].p_thread, NULL))
			write(2, THREAD_JOIN_ERR, 26);
}

int	main(int ac, char **av)
{
	int			i;
	t_data		table_datas;

	if (arg_count_checker(ac))
	{
		if (first_arg_checker(av, &table_datas))
			return (FAIL_RETURN);
		if (arg_mutex_init_and_checker(av, &table_datas))
			return (FAIL_RETURN);
		if (allocation(&table_datas))
			return (mutex_destroy(&table_datas, FNSH), FAIL_RETURN);
		if (forks_philo_init(&table_datas))
			return (free_and_destroy(&table_datas), FAIL_RETURN);
		if (table_datas.number_of_philo == 1)
			if (if_one_philo(&table_datas))
				return (free_and_destroy(&table_datas), FAIL_RETURN);
		if (start_algorithm(&table_datas, &i))
			return (free_and_destroy(&table_datas), FAIL_RETURN);
		anyone_alive(&table_datas, &i);
		join_function(&table_datas, &i);
		free_and_destroy(&table_datas);
	}
}
