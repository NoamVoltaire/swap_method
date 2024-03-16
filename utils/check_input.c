/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:18:19 by noam              #+#    #+#             */
/*   Updated: 2024/03/11 22:47:58 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

void	check_input(char **arg)
{
	long	index;
	int		i;

	i = 0;
	index = 0;
	while (arg[i])
	{
		if (!is_digit(arg[i]))
			error(NULL, NULL);
		if (ft_atol(arg[i]) > 2147483647 || ft_atol(arg[i]) < -2147483648)
			error(NULL, NULL);
		index = 1;
		while (arg[i + index])
		{
			if (!ft_strncmp(arg[i], arg[i + index], 12))
				error(NULL, NULL);
			index++;
		}
		i++;
	}
}