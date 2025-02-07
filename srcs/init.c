/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:31:00 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/06 08:36:20 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init(t_table *table, char *argv[])
{
	table->num_of_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->eat_count = -1;
	table->end_sim = false;
	if (argv[5])
		table->eat_count = ft_atoi(argv[5]);
	pthread_mutex_init(&table->end_mutex, NULL);
	pthread_mutex_init(&table->log_mutex, NULL);
	pthread_mutex_init(&table->philo_mutex, NULL);
	init_fork(table);
	init_philo(table);
	return (1);
}

int	init_philo(t_table *table)
{
	t_philo	*philo;
	int		i;

	table->philo = (t_philo *)malloc(sizeof(t_philo) * table->num_of_philo);
	philo = table->philo;
	i = -1;
	while (++i < table->num_of_philo)
	{
		philo[i].id = i + 1;
		philo[i].eat_count = 0;
		philo[i].left_fork = &table->fork[i];
		philo[i].right_fork = &table->fork[(i + 1) % table->num_of_philo];
		pthread_mutex_init(&philo[i].eat_mutex, NULL);
		pthread_mutex_init(&philo[i].last_eat_mutex, NULL);
	}
	return (1);
}

int	init_fork(t_table *table)
{
	t_mutex	*fork;
	int		i;

	table->fork = (t_mutex *)malloc(sizeof(t_mutex) * table->num_of_philo);
	fork = table->fork;
	i = -1;
	while (++i < table->num_of_philo)
		pthread_mutex_init(&fork[i], NULL);
	return (1);
}

int	clean_up(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->num_of_philo)
	{
		pthread_mutex_destroy(&table->fork[i]);
		pthread_mutex_destroy(&table->philo[i].eat_mutex);
		pthread_mutex_destroy(&table->philo[i].last_eat_mutex);
	}
	free(table->fork);
	free(table->philo);
	pthread_mutex_destroy(&table->end_mutex);
	pthread_mutex_destroy(&table->log_mutex);
	pthread_mutex_destroy(&table->philo_mutex);
	return (1);
}
