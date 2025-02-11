/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- wwan-ab-@student.42kl.edu.my      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:31:44 by wwan-ab-          #+#    #+#             */
/*   Updated: 2025/02/06 08:31:47 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	is_num(char *str);

int	validate(int argc, char *argv[])
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		printf("Error: wrong number of arguments\n");
		return (0);
	}
	i = 0;
	while (++i < argc)
	{
		if (!is_num(argv[i]) || ft_atol(argv[i]) < 0)
		{
			if (!is_num(argv[i]))
				printf("Error: arguments must be positive integers\n");
			else if (ft_atol(argv[i]) < 0)
				printf("Error: integer overflow\n");
			return (0);
		}
	}
	if (ft_atol(argv[1]) <= 0)
	{
		printf("Error: number of philosophers must be greater than 0\n");
		return (0);
	}
	return (1);
}

static int	is_num(char *str)
{
	int	i;

	if (str[0] == '\0')
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}
