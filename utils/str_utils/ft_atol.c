/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:46:51 by noam              #+#    #+#             */
/*   Updated: 2024/03/11 20:39:45 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap_header.h"

long	ft_atol(const char *digit_str)
{
	int		i;
	int		sign;
	long	sum;

	sum = 0;
	sign = 1;
	i = 0;
	if (digit_str[i] == '+' || digit_str[i] == '-')
	{
		if (digit_str[i] == '-')
			sign = -1;
		i++;
	}
	while (digit_str[i] >= '0' && digit_str[i] <= '9')
	{
		sum = sum * 10 + (digit_str[i] - '0');
		i++;
	}
	return (sum * sign);
}
