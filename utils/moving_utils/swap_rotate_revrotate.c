/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rotate_revrotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:00:56 by noam              #+#    #+#             */
/*   Updated: 2024/03/24 19:28:42 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap_header.h"

void	swap(t_stack **lst, char stack)
{
	t_stack	*tmp;

	if ((*lst)->next->next == (*lst))
	{
		(*lst) = (*lst)->next;
		return ;
	}
	tmp = (*lst)->next;
	(*lst)->next = tmp->next;
	tmp->next->prev = (*lst);
	tmp->next = *lst;
	tmp->prev = (*lst)->prev;
	tmp->prev->next = tmp;
	(*lst)->prev = tmp;
	*lst = tmp;
	if (stack == 'a')
		write(1, "sa\n", 3);
	else if (stack == 'b')
		write(1, "sb\n", 3);
}

void	rotate(t_stack **lst, char stack, t_global *global)
{
	global->nb_ops++;
	*lst = (*lst)->next;
	if (global->debug)
		return ;
	if (stack == 'a')
		write(1, "ra\n", 3);
	else if (stack == 'b')
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_stack **lst, char stack, t_global *global)
{
	global->nb_ops++;
	*lst = (*lst)->prev;
	if (global->debug)
		return ;
	if (stack == 'a')
		write(1, "rra\n", 4);
	else if (stack == 'b')
		write(1, "rrb\n", 4);
}
