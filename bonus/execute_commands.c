/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 02:09:22 by noam              #+#    #+#             */
/*   Updated: 2024/03/29 10:55:38 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

void	exec_swap(char *cmd, t_stack **a, t_stack **b, t_global *global)
{
	if (ft_strncmp(cmd, "sa", 2) == 0)
		swap(a, 'a', global);
	else if (ft_strncmp(cmd, "sb", 2) == 0)
		swap(b, 'b', global);
	else if (ft_strncmp(cmd, "ss", 2) == 0)
		ss(a, b, global);
}

void	exec_rotate(char *cmd, t_stack **a, t_stack **b, t_global *global)
{
	if (ft_strncmp(cmd, "rra", 3) == 0)
		reverse_rotate(a, 'a', global);
	else if (ft_strncmp(cmd, "rrb", 3) == 0)
		reverse_rotate(b, 'b', global);
	else if (ft_strncmp(cmd, "rrr", 3) == 0)
		rrr(a, b, global);
	else if (ft_strncmp(cmd, "ra", 2) == 0)
		rotate(a, 'a', global);
	else if (ft_strncmp(cmd, "rb", 2) == 0)
		rotate(b, 'b', global);
	else if (ft_strncmp(cmd, "rr", 2) == 0)
		rr(a, b, global);
}

void	exec_push(char *cmd, t_stack **a, t_stack **b, t_global *global)
{
	if (ft_strncmp(cmd, "pb", 2) == 0)
		push(a, b, 'b', global);
	else if (ft_strncmp(cmd, "pa", 2) == 0)
		push(b, a, 'a', global);
}

void	execute_commands(char **cmnds, t_stack **a, int len)
{
	t_stack			*b;
	int				i;
	t_global		*global;

	b = NULL;
	i = 0;
	global = NULL;
	global = init_global(a, len);
	while (cmnds[i])
	{
		if (cmnds[i][0] == 'p')
			exec_push(cmnds[i], a, &b, global);
		else if (cmnds[i][0] == 'r')
			exec_rotate(cmnds[i], a, &b, global);
		else if (cmnds[i][0] == 's')
			exec_swap(cmnds[i], a, &b, global);
		i++;
	}
	free_stack(&b);
	free(global->sorted);
	free(global);
}
