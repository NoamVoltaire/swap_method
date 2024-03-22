/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_comparing_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:55:15 by noam              #+#    #+#             */
/*   Updated: 2024/03/21 16:34:45 by noam             ###   ########.fr       */
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
	t_stack	*tmp;

	tmp = (*lst)->prev;
	while ((*lst) != tmp)
	{
		if (!next_node_is_bigger(*lst))
			return (0);
		(*lst) = (*lst)->next;
	}
	return (1);
}
