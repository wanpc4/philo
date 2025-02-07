/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:31:08 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/06 08:31:11 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	is_end_sim(t_table *table)
{
	pthread_mutex_lock(&table->end_mutex);
	if (table->end_sim)
	{
		pthread_mutex_unlock(&table->end_mutex);
		return (1);
	}
	pthread_mutex_unlock(&table->end_mutex);
	return (0);
}

int	is_starving(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&philo->last_eat_mutex);
	if (get_time_ms() - philo->last_eat_time >= table->time_to_die)
	{
		p_die(philo, table);
		pthread_mutex_unlock(&philo->last_eat_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->last_eat_mutex);
	return (0);
}

int	all_ate_enough(t_table *table)
{
	int	count;
	int	i;

	if (table->eat_count == -1)
		return (0);
	count = 0;
	i = -1;
	while (++i < table->num_of_philo)
	{
		pthread_mutex_lock(&table->philo[i].eat_mutex);
		if (table->philo[i].eat_count >= table->eat_count)
			count += 1;
		pthread_mutex_unlock(&table->philo[i].eat_mutex);
	}
	if (count == table->num_of_philo)
		return (1);
	return (0);
}
