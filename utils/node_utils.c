/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:44:39 by noam              #+#    #+#             */
/*   Updated: 2024/03/08 18:02:00 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

t_stack	*new_node(int content, int index)
{
	t_stack	*mynode;

	mynode = (t_stack *)malloc(sizeof(t_stack));
	if (mynode == NULL)
		return (NULL);
	mynode->content = content;
	mynode->index = index;
	mynode->next = mynode;
	mynode->prev = mynode;
	return (mynode);
}

void	add_to_front(t_stack **lst, t_stack *new)
{
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	new->next = (*lst);
	new->prev = (*lst)->prev;
	(*lst)->prev->next = new;
	(*lst)->prev = new;
	*lst = new;
}

void	fillstack(t_stack **a, char **array, const int len)
{
	t_stack	*tmp;
	int		last;

	last = len - 1;
	*a = new_node(ft_atol(array[last]), 0);
	last--;
	while (last >= 0)
	{
		tmp = new_node(ft_atol(array[last]), 0);
		add_to_front(a, tmp);
		last--;
	}
	return ;
}
