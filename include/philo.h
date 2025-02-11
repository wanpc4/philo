/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:32:02 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/07 07:24:08 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>

# define DELAY 10
# define WAIT 1000
# define INT_MAX 2147483647
# define INT_MIN (-2147483648)
# define DEBUG "printf"

typedef pthread_mutex_t	t_mutex;

typedef struct s_philo
{
	int			id;
	int			eat_count;
	long		last_eat_time;
	t_mutex		*left_fork;
	t_mutex		*right_fork;
	t_mutex		eat_mutex;
	t_mutex		last_eat_mutex;
	pthread_t	thread;
}	t_philo;

typedef struct s_table
{
	int		num_of_philo;
	int		time_to_sleep;
	int		time_to_eat;
	int		time_to_die;
	int		eat_count;
	long	start_time;
	bool	end_sim;
	t_mutex	philo_mutex;
	t_mutex	end_mutex;
	t_mutex	log_mutex;
	t_mutex	*fork;
	t_philo	*philo;
}	t_table;

int		init(t_table *table, char *argv[]);
int		init_philo(t_table *table);
int		init_fork(t_table *table);
int		clean_up(t_table *table);
int		validate(int argc, char *argv[]);
int		run_sim(t_table *table);
int		is_end_sim(t_table *table);
int		is_starving(t_table *table, t_philo *philo);
int		all_ate_enough(t_table *table);
int		ft_atol(const char *str);

void	log_activity(t_table *table, int id, char *msg);
void	usleep_ms(long ms);
void	*monitor(void *data);
void	*start_routine(void *data);
void	sync_routine(t_table *table);
void	p_take_forks(t_philo *philo, t_table *table);
void	p_eat(t_philo *philo, t_table *table);
void	p_sleep(t_philo *philo, t_table *table);
void	p_think(t_philo *philo, t_table *table);
void	p_die(t_philo *philo, t_table *table);

long	get_time_ms(void);
#endif
