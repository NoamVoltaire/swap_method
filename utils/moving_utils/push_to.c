/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:23:02 by noam              #+#    #+#             */
/*   Updated: 2024/03/09 18:31:55 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap_header.h"

static void	write_push_command(char to_stack_name)
{
	if (to_stack_name == 'b')
		write(1, "pb\n", 3);
	else if (to_stack_name == 'a')
		write(1, "pa\n", 3);
}

void	push(t_stack **lst, t_stack **to_stack, char to_stack_name)
{
	t_stack	*tmp;

	if (!(*lst))
		return ;
	write_push_command(to_stack_name);
	if (!(*to_stack))
		*to_stack = new_node((*lst)->content);
	else
	{
		tmp = new_node((*lst)->content);
		add_to_front(to_stack, tmp);
	}
	if ((*lst)->next == *lst)
	{
		free (*lst);
		*lst = NULL;
		return ;
	}
	tmp = (*lst)->next;
	(*lst)->prev->next = (*lst)->next;
	(*lst)->next->prev = (*lst)->prev;
	free(*lst);
	*lst = tmp;
}
