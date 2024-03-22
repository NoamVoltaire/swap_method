/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:23:02 by noam              #+#    #+#             */
/*   Updated: 2024/03/21 16:02:39 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap_header.h"

static void	global_settings(t_global *global, char dest_name)
{
	if (dest_name == 'a')
	{
		global->len_a++;
		global->len_b--;
	}
	else
	{
		global->len_a--;
		global->len_b++;
	}
	global->nb_ops++;
}

static	void	write_push_command(char to_stack_name)
{
	if (to_stack_name == 'b')
		write(1, "pb\n", 3);
	else if (to_stack_name == 'a')
		write(1, "pa\n", 3);
}

void	push(t_stack **lst, t_stack **dest,	char dest_name, t_global *global)
{
	t_stack	*tmp;

	if (!(*lst))
		return ;
	global_settings(global, dest_name);
	if (!global->debug)
		write_push_command(dest_name);
	if (!(*dest))
		*dest = new_node((*lst)->content);
	else
	{
		tmp = new_node((*lst)->content);
		add_to_front(dest, tmp);
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
