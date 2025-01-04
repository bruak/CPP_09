/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_sleep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:16:38 by bsoykan           #+#    #+#             */
/*   Updated: 2024/01/22 16:56:13 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>
#include <unistd.h>

#define ONE_SEC 1000
#define ONE_MILISEC 1000

long	long	int	hell_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (write(2, GET_TIME_ERR, 27), FAIL_RETURN);
	return ((tv.tv_sec * ONE_SEC) + (tv.tv_usec / ONE_MILISEC));
}

void	sleep_implement(long time)
{
	long long int	start;

	start = hell_time();
	while (hell_time() - start < time)
		usleep(200);
}

void	modding_2(t_philo *philo)
{
	if (philo->p_id % 2 == 0)
		sleep_implement(10);
}
