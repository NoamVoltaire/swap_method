/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_comparing_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:55:15 by noam              #+#    #+#             */
/*   Updated: 2024/05/09 16:05:48 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap_header.h"

int	next_node_is_bigger(t_stack *lst)
{
	if (!lst->next || !lst)
		return (0);
	return (lst->content < lst->next->content);
}

int	stack_is_sorted(t_stack **lst)
{
	t_stack	*_head;
	t_stack	*tmp;

	_head = (*lst)->prev;
	tmp = *lst;
	while (tmp != _head)
	{
		if (!next_node_is_bigger(tmp))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
