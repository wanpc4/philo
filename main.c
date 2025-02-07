/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:30:40 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/06 08:30:48 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int argc, char *argv[])
{
	t_table	table;

	if (!validate(argc, argv))
		return (1);
	init(&table, argv);
	run_sim(&table);
	clean_up(&table);
	return (0);
}
