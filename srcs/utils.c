/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:31:36 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/06 08:37:50 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	log_activity(t_table *table, int id, char *msg)
{
	long	current_time;

	current_time = get_time_ms() - WAIT;
	pthread_mutex_lock(&table->log_mutex);
	if (is_end_sim(table))
	{
		pthread_mutex_unlock(&table->log_mutex);
		return ;
	}
	printf("%ld %d %s\n\n", current_time - table->start_time, id, msg);
	pthread_mutex_unlock(&table->log_mutex);
}

void	usleep_ms(long ms)
{
	long	start_time;

	start_time = get_time_ms();
	while ((get_time_ms() - start_time) < ms)
		usleep(500);
}

long	get_time_ms(void)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

int	ft_atoi(const char *str)
{
	int	count;
	int	sign;
	int	converter;

	count = 0;
	sign = 1;
	converter = 0;
	while ((str[count] == ' ') || (str[count] >= '\t' && str[count] <= '\r'))
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign = -1;
		count++;
	}
	while ((str[count] >= '0') && (str[count] <= '9'))
	{
		converter = (converter * 10) + (str[count] - '0');
		count++;
	}
	return (converter * sign);
}
