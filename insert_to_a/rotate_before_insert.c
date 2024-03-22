/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_before_insert.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:14:45 by noam              #+#    #+#             */
/*   Updated: 2024/03/21 18:30:43 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

void	rotate_both(t_stack **a, t_stack **b, t_global *global)
{
	while (global->target_node->a_rot > 0 && global->target_node->b_rot > 0)
	{
		rr(a, b, global);
		global->target_node->a_rot--;
		global->target_node->b_rot--;
	}
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_global *global)
{
	while (global->target_node->a_rot < 0 && global->target_node->b_rot < 0)
	{
		rrr(a, b, global);
		global->target_node->a_rot++;
		global->target_node->b_rot++;
	}
}

void	rotate_single(t_stack **lst, char stack_name, int rotation, t_global *global)
{
	while (rotation > 0 && rotation--)
		rotate(lst, stack_name, global);
	while (rotation < 0 && rotation++)
		reverse_rotate(lst, stack_name, global);
}

void	rotate_before_insert(t_stack **a, t_stack **b, t_global *global)
{
	rotate_both(a, b, global);
	rev_rotate_both(a, b, global);
	rotate_single(a, 'a', global->target_node->a_rot, global);
	rotate_single(b, 'b', global->target_node->b_rot, global);
}

