/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:18:19 by noam              #+#    #+#             */
/*   Updated: 2024/05/10 13:37:15 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

void	check_input(char **arg, int mallocd)
{
	long	index;
	int		i;

	i = 0;
	index = 0;
	if (!arg[i])
		error(arg, mallocd);
	while (arg[i])
	{
		if (!is_digit(arg[i]))
			error(arg, mallocd);
		if (ft_atol(arg[i]) > 2147483647 || ft_atol(arg[i]) < -2147483648)
			error(arg, mallocd);
		index = 1;
		while (arg[i + index])
		{
			if (ft_atol(arg[i]) == ft_atol(arg[i + index]))
				error(arg, mallocd);
			index++;
		}
		i++;
	}
}
