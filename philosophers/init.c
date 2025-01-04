/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:16:23 by bsoykan           #+#    #+#             */
/*   Updated: 2024/01/22 16:47:17 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

#define SIXTY 60
#define CANNOT_ZERO 0

int	arg_mutex_init_and_checker(char **av, t_data *table_datas)
{
	int	control_flag;

	control_flag = 0;
	table_datas->death_duration = ft_atoi(av[2]);
	table_datas->meal_duration = ft_atoi(av[3]);
	table_datas->sleep_duration = ft_atoi(av[4]);
	table_datas->dead_flag = 0;
	table_datas->meal_flag = 0;
	table_datas->break_flag = 0;
	table_datas->beginning_time = hell_time();
	if (av[5])
		table_datas->numbers_of_meals = ft_atoi(av[5]);
	else
		table_datas->numbers_of_meals = -1;
	control_flag = mutex_init_realize(table_datas);
	control_flag = arg_control(table_datas, av);
	if (control_flag == 1)
		return (control_flag);
	return (ZERO_RETURN);
}

int	arg_control(t_data *table_datas, char **av)
{
	if (table_datas->death_duration < SIXTY
		|| table_datas->meal_duration < SIXTY
		|| table_datas->sleep_duration < SIXTY)
		return (write(2, _60MS_ERR, 38), SUCCESS_RETURN);
	if (av[5] && (table_datas->numbers_of_meals < CANNOT_ZERO
			|| table_datas->numbers_of_meals == CANNOT_ZERO))
		return (write(2, _60MS_ERR, 38), SUCCESS_RETURN);
	return (ZERO_RETURN);
}

int	mutex_init_realize(t_data *table_datas)
{
	if (pthread_mutex_init(&table_datas->meal_counting_mutex, NULL))
		return (write(2, MTX_ERR, 25), SUCCESS_RETURN);
	if (pthread_mutex_init(&table_datas->mutex_overall, NULL))
		return (write(2, MTX_ERR, 25), mutex_destroy(table_datas, CNT),
			SUCCESS_RETURN);
	if (pthread_mutex_init(&table_datas->kill_mutex, NULL))
		return (write(2, MTX_ERR, 25), mutex_destroy(table_datas, CNT_CHK),
			SUCCESS_RETURN);
	if (pthread_mutex_init(&table_datas->mutex_duration, NULL))
		return (write(2, MTX_ERR, 25),
			mutex_destroy(table_datas, CNT_CHK_DIE), SUCCESS_RETURN);
	if (pthread_mutex_init(&table_datas->mutex_print, NULL))
		return (write(2, MTX_ERR, 25),
			mutex_destroy(table_datas, CNT_CHK_DIE_TIME), SUCCESS_RETURN);
	return (ZERO_RETURN);
}

int	forks_philo_init(t_data *table_datas)
{
	int		i;

	i = -1;
	while (++i < table_datas->number_of_philo)
	{
		philo_data_init(table_datas, i);
		table_datas->philos[i].l_fork = i;
		if (i == 0)
			table_datas->philos[i].r_fork = table_datas->number_of_philo - 1;
		else
			table_datas->philos[i].r_fork = i - 1;
	}
	return (ZERO_RETURN);
}

void	philo_data_init(t_data *table_datas, int i)
{
	table_datas->philos[i].p_id = i + 1;
	table_datas->philos[i].meals_eaten = 0;
	table_datas->philos[i].data = table_datas;
	table_datas->philos[i].last_time_eat = hell_time();
}
