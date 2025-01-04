/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:16:38 by bsoykan           #+#    #+#             */
/*   Updated: 2024/01/22 16:56:13 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

void	single_message(t_data *data, int *i, char *str)
{
	printf("%lld %d %s", hell_time() - data->beginning_time,
		data->philos[*i].p_id, str);
}

int	meals_counter_control(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&data->mutex_overall);
	while (++i < data->number_of_philo
		&& data->philos[i].meals_eaten == data->numbers_of_meals)
	{
		pthread_mutex_unlock(&data->mutex_overall);
		pthread_mutex_lock(&data->meal_counting_mutex);
		data->meal_flag++;
		pthread_mutex_unlock(&data->meal_counting_mutex);
		pthread_mutex_lock(&data->mutex_overall);
	}
	pthread_mutex_unlock(&data->mutex_overall);
	pthread_mutex_lock(&data->meal_counting_mutex);
	if (data->meal_flag == data->number_of_philo)
	{
		data->break_flag = 1;
		pthread_mutex_unlock(&data->meal_counting_mutex);
		return (SUCCESS_RETURN);
	}
	pthread_mutex_unlock(&data->meal_counting_mutex);
	return (ZERO_RETURN);
}

int	anyone_alive(t_data *data, int *i)
{
	while (1)
	{
		while (++*i < data->number_of_philo)
		{
			if (meals_counter_control(data))
				return (ZERO_RETURN);
			pthread_mutex_lock(&data->mutex_duration);
			if (hell_time() - data->philos[*i].last_time_eat
				>= data->death_duration)
			{
				pthread_mutex_unlock(&data->mutex_duration);
				pthread_mutex_lock(&data->mutex_overall);
				data->dead_flag = 1;
				pthread_mutex_unlock(&data->mutex_overall);
				if (!data->break_flag)
					single_message(data, i, KILL);
				return (ZERO_RETURN);
			}
			pthread_mutex_unlock(&data->mutex_duration);
		}
		*i = -1;
	}
	return (SUCCESS_RETURN);
}

void	*philosopher_routine(void *internal_pointer)
{
	t_philo		*philo;

	philo = (t_philo *)internal_pointer;
	modding_2(philo);
	pthread_mutex_lock(&philo->data->mutex_overall);
	while (!philo->data->dead_flag
		&& philo->meals_eaten != philo->data->numbers_of_meals)
	{
		pthread_mutex_unlock(&philo->data->mutex_overall);
		philo_eating(philo);
		pthread_mutex_lock(&philo->data->mutex_overall);
		if (if_eaten_enough(philo) == 1)
			break ;
		pthread_mutex_unlock(&philo->data->mutex_overall);
		sleep_and_think(philo);
		pthread_mutex_lock(&philo->data->mutex_overall);
	}
	pthread_mutex_unlock(&philo->data->mutex_overall);
	return (NULL);
}

int	if_eaten_enough(t_philo *philo)
{
	if (philo->meals_eaten == philo->data->numbers_of_meals
		|| philo->data->dead_flag)
		return (SUCCESS_RETURN);
	return (ZERO_RETURN);
}
