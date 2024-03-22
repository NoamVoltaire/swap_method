/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:54:29 by noam              #+#    #+#             */
/*   Updated: 2024/03/21 19:10:23 by noam             ###   ########.fr       */
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
	// printf("j before if = %d\n", j);
	if (j > len_a / 2)
	{
		j = (len_a - j) * -1;
	// printf("len_a = %d\n", len_a);
	// printf("j after if = %d\n", j);
		
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
	// printf("b->a_rot = %d b->b_rot = %d\n", (*b)->a_rot, (*b)->b_rot);
	rot++;
	(*b) = (*b)->next;
	while ((*b) != tmp)
	{
		(*b)->a_rot = find_insertion_point((*b)->content, *a, global->len_a);
		if (rot > global->len_b / 2)
			(*b)->b_rot = (global->len_b - rot) * -1;
		else
			(*b)->b_rot = rot;
		// printf("b->a_rot = %d b->b_rot = %d\n", (*b)->a_rot, (*b)->b_rot);
		rot++;
		(*b) = (*b)->next;
	}
}


// struct	s_best_rotations
// {
// 	int		nb_ra;
// 	int		nb_rb;
// 	int		nb_rr;
// 	int		nb_rra;
// 	int		nb_rrb;
// 	int		nb_rrr;
// 	int		total;
// };



