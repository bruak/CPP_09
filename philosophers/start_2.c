/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:16:42 by bsoykan           #+#    #+#             */
/*   Updated: 2024/01/28 15:44:48 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

void	status_message(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex_print);
	pthread_mutex_lock(&philo->data->mutex_overall);
	if (!philo->data->dead_flag)
	{
		printf("%lld %d %s\n", hell_time()
			- philo->data->beginning_time, philo->p_id, str);
	}
	pthread_mutex_unlock(&philo->data->mutex_overall);
	pthread_mutex_unlock(&philo->data->mutex_print);
}

void	taken_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->l_fork]);
	status_message(TAKE_FORK, philo);
	pthread_mutex_lock(&philo->data->forks[philo->r_fork]);
	status_message(TAKE_FORK, philo);
}

void	sleep_and_think(t_philo *philo)
{
	status_message(SLEEP, philo);
	sleep_implement(philo->data->sleep_duration);
	status_message(SLEEP, philo);
}

void	philo_eating(t_philo *philo)
{
	taken_forks(philo);
	status_message(EAT, philo);
	sleep_implement(philo->data->meal_duration);
	pthread_mutex_lock(&philo->data->mutex_duration);
	philo->last_time_eat = hell_time();
	pthread_mutex_unlock(&philo->data->mutex_duration);
	pthread_mutex_lock(&philo->data->mutex_overall);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->mutex_overall);
	unlock_forks_mutex(philo);
}

void	unlock_forks_mutex(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->r_fork]);
}
