/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:54:29 by noam              #+#    #+#             */
/*   Updated: 2024/03/24 19:31:10 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

static	int	find_insertion_point(int e, t_stack *a, int len_a)
{
	t_stack	*tmp;
	int		j;

	tmp = a;
	j = 0;
	while (tmp->content < e || tmp->prev->content > e)
	{
		j++;
		tmp = tmp->next;
	}
	if (j > len_a / 2)
	{
		j = (len_a - j) * -1;
	}
	return (j);
}

void	rotation_instructions(t_stack **a, t_stack **b, t_global *global)
{
	t_stack	*tmp;
	int		rot;

	tmp = (*b);
	rot = 0;
	(*b)->a_rot = find_insertion_point((*b)->content, *a, global->len_a);
	(*b)->b_rot = rot;
	rot++;
	(*b) = (*b)->next;
	while ((*b) != tmp)
	{
		(*b)->a_rot = find_insertion_point((*b)->content, *a, global->len_a);
		if (rot > global->len_b / 2)
			(*b)->b_rot = (global->len_b - rot) * -1;
		else
			(*b)->b_rot = rot;
		rot++;
		(*b) = (*b)->next;
	}
}
