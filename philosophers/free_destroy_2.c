/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_destroy_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:16:11 by bsoykan           #+#    #+#             */
/*   Updated: 2024/01/28 15:41:37 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_destroy_5(t_data *datas)
{
	pthread_mutex_destroy(&datas->meal_counting_mutex);
	pthread_mutex_destroy(&datas->mutex_overall);
}

void	mutex_destroy_4(t_data *datas)
{
	pthread_mutex_destroy(&datas->meal_counting_mutex);
	pthread_mutex_destroy(&datas->mutex_overall);
	pthread_mutex_destroy(&datas->kill_mutex);
}

void	mutex_destroy_3(t_data *datas)
{
	pthread_mutex_destroy(&datas->meal_counting_mutex);
	pthread_mutex_destroy(&datas->mutex_overall);
	pthread_mutex_destroy(&datas->kill_mutex);
	pthread_mutex_destroy(&datas->mutex_duration);
}

void	mutex_destroy_2(t_data *datas)
{
	pthread_mutex_destroy(&datas->meal_counting_mutex);
	pthread_mutex_destroy(&datas->mutex_overall);
	pthread_mutex_destroy(&datas->kill_mutex);
	pthread_mutex_destroy(&datas->mutex_duration);
	pthread_mutex_destroy(&datas->mutex_print);
}

void	if_mutex_destroy_finish(t_data *datas)
{
	pthread_mutex_destroy(&datas->meal_counting_mutex);
	pthread_mutex_destroy(&datas->mutex_overall);
	pthread_mutex_destroy(&datas->kill_mutex);
	pthread_mutex_destroy(&datas->mutex_duration);
	pthread_mutex_destroy(&datas->mutex_print);
}
