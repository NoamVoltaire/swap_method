/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:44:39 by noam              #+#    #+#             */
/*   Updated: 2024/03/11 20:19:23 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap_header.h"

t_stack	*new_node(int content)
{
	t_stack	*mynode;

	mynode = (t_stack *)malloc(sizeof(t_stack));
	if (mynode == NULL)
		return (NULL);
	mynode->content = content;
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
	*a = new_node(ft_atol(array[last]));
	last--;
	while (last >= 0)
	{
		tmp = new_node(ft_atol(array[last]));
		add_to_front(a, tmp);
		last--;
	}
	return ;
}

void	free_stack(t_stack **lst)
{
	t_stack	*last_node;
	t_stack	*tmp;

	if (!(*lst))
		return ;
	last_node = (*lst)->prev;
	tmp = (*lst)->next;
	while ((*lst) && last_node != *lst)
	{
		free(*lst);
		*lst = tmp;
		tmp = (*lst)->next;
	}
	free(*lst);
	*lst = NULL;
}
