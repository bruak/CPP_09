/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:16:11 by bsoykan           #+#    #+#             */
/*   Updated: 2024/01/28 15:41:37 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <unistd.h>

int	arg_count_checker(int ac)
{
	if (ac < 5 || ac > 6)
		return (write(2, ARG_ERR, 23), ZERO_RETURN);
	return (SUCCESS_RETURN);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (ZERO_RETURN);
	return (s1[i] - s2[i]);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	mutex_destroy(t_data *datas, char *mutex_name)
{
	int	i;

	i = 0;
	if (ft_strncmp(mutex_name, CNT, ft_strlen(CNT)) == 0)
		pthread_mutex_destroy(&datas->meal_counting_mutex);
	else if (ft_strncmp(mutex_name, CNT_CHK, ft_strlen(CNT_CHK)) == 0)
		mutex_destroy_5(datas);
	else if (ft_strncmp(mutex_name, CNT_CHK_DIE, ft_strlen(CNT_CHK_DIE)) == 0)
		mutex_destroy_4(datas);
	else if (ft_strncmp(mutex_name, CNT_CHK_DIE_TIME,
			ft_strlen(CNT_CHK_DIE_TIME)) == 0)
		mutex_destroy_3(datas);
	else if (ft_strncmp(mutex_name, CNT_CHK_DIE_TME_WRTE,
			ft_strlen(CNT_CHK_DIE_TME_WRTE)) == 0)
		mutex_destroy_2(datas);
	else if (ft_strncmp(mutex_name, FNSH, ft_strlen(FNSH)) == 0)
		if_mutex_destroy_finish(datas);
	else if (ft_strncmp(mutex_name, ALL, ft_strlen(ALL)) == 0)
	{
		mutex_destroy(datas, FNSH);
		while (i < datas->number_of_philo)
			if (datas->forks)
				pthread_mutex_destroy(&datas->forks[i++]);
	}
}

void	free_and_destroy(t_data *datas)
{
	mutex_destroy(datas, ALL);
	if (datas->forks)
		free(datas->forks);
	if (datas->philos)
		free(datas->philos);
}
