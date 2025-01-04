/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:16:33 by bsoykan           #+#    #+#             */
/*   Updated: 2024/01/20 18:28:15 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>

# define MAX_INT 2147483647

/***************return_value*************/
# define FAIL_RETURN -1
# define SUCCESS_RETURN 1
# define ZERO_RETURN 0

/***************thread_mutex_alloc_err*************/
# define ARG_ERR "Error: wrong argument\n"
# define MTX_ERR "Error: mutex init error\n"
# define ALOCK_ERR "Error: allocation error\n"
# define GET_TIME_ERR "Error: gettimeofday error\n"
# define THREAD_JOIN_ERR "Error: thread join error\n"
# define THREAD_CREATE_ERR "Error: thread create error\n"
# define _60MS_ERR "Error: time must be bigger than 60ms\n"
# define ARG_POZIT_ERR "Error: philo_num must be a positive\n"
/***************mutex_types*************/
# define ALL "all"
# define CNT "count"
# define FNSH "finish"
# define CNT_CHK "count_check"
# define CNT_CHK_DIE "count_check_die"
# define CNT_CHK_DIE_TIME "count_check_die_time"
# define CNT_CHK_DIE_TME_WRTE "count_check_die_time_write"

/***************algorithm*************/
# define KILL "died\n"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define TAKE_FORK "has taken a fork"

typedef struct s_philo
{
	struct s_data	*data;
	int				p_id;
	int				l_fork;
	int				r_fork;
	int				meals_eaten;
	long long int	last_time_eat;
	pthread_t		p_thread;
}	t_philo;

typedef struct s_data
{
	t_philo			*philos;
	int				dead_flag;
	int				meal_flag;
	int				break_flag;
	int				meal_duration;
	long long int	beginning_time;
	int				death_duration;
	int				sleep_duration;
	int				number_of_philo;
	int				numbers_of_meals;
	pthread_mutex_t	meal_counting_mutex;
	pthread_mutex_t	mutex_duration;
	pthread_mutex_t	mutex_overall;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	kill_mutex;
	pthread_mutex_t	*forks;
}	t_data;

/*********************time stuff**********************/
long long int	hell_time(void);
void			modding_2(t_philo *philosopher);
void			sleep_implement(long meal_duration);

/*********************arg and init stuff**********************/
int				ft_atoi(char *str);
int				allocation(t_data *table_datas);
int				forks_philo_init(t_data *table_datas);
int				mutex_init_realize(t_data *table_datas);
int				arg_control(t_data *table_datas, char **av);
void			philo_data_init(t_data *table_datas, int i);
int				first_arg_checker(char **av, t_data *table_datas);
int				convert_string_to_int(char *str, int i, int result);
int				arg_mutex_init_and_checker(char **av, t_data *table_datas);

/*********************routine**********************/
int				arg_count_checker(int ac);
void			taken_forks(t_philo *philo);
void			philo_eating(t_philo *philo);
void			sleep_and_think(t_philo *philo);
int				if_eaten_enough(t_philo *philo);
int				if_one_philo(t_data *table_datas);
void			unlock_forks_mutex(t_philo *philo);
int				anyone_alive(t_data *data, int *i);
int				start_algorithm(t_data *data, int *i);
void			status_message(char *str, t_philo *philo);
void			*philosopher_routine(void *internal_pointer);

/*********************free and destroy stuff**********************/
void			mutex_destroy_5(t_data *datas);
void			mutex_destroy_4(t_data *datas);
void			mutex_destroy_3(t_data *datas);
void			mutex_destroy_2(t_data *datas);
void			free_and_destroy(t_data *datas);
void			if_mutex_destroy_finish(t_data *datas);
void			mutex_destroy(t_data *datas, char *mutex_name);

#endif
