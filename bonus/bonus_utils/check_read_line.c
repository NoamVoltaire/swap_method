/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_read_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 01:44:58 by noam              #+#    #+#             */
/*   Updated: 2024/05/09 16:12:43 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap_header.h"

int	is_cmd(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 's' && str[i] != 'r' && str[i] != 'p'
			&& str[i] != 'a' && str[i] != 'b' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	check_read_line(char *big_line)
{
	if (big_line == NULL)
		error_ko(NULL);
	if (!is_cmd(big_line))
		error_ko(big_line);
}
