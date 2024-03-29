/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 01:06:43 by noam              #+#    #+#             */
/*   Updated: 2024/03/29 10:57:01 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

char	*read_all(void)
{
	char	*read_line;
	char	*big_str;

	big_str = NULL;
	while (1)
	{
		read_line = get_next_line(0);
		if (read_line == NULL)
			break ;
		big_str = ft_strjoin(big_str, read_line);
	}
	return (big_str);
}

void	read_and_exec(t_stack **a, int len)
{
	char	*big_read_line;
	char	**instructions;

	big_read_line = read_all();
	check_read_line(big_read_line);
	instructions = ft_split(big_read_line, '\n');
	free(big_read_line);
	execute_commands(instructions, a, len);
	free_array(instructions);
}
