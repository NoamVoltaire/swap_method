/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iinsert_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:59:03 by noam              #+#    #+#             */
/*   Updated: 2024/03/18 04:17:03 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/node_utils/node_utils.c"
#include "utils/str_utils/ft_atol.c"
#include "utils/str_utils/ft_split.c"
#include "utils/moving_utils/push_to.c"
#include "utils/moving_utils/rr_rrr_ss.c"
#include "utils/moving_utils/swap_rotate_revrotate.c"
#include "int_array_sorted.c"
#include "insert_to_a/rotate_before_insert.c"
#include "insert_to_a/find_cheapest.c"
#include "insert_to_a/rotation_instructions.c"

#include "push_swap_header.h"



void	pre_sort_to_b(t_global global)
{
	some_type_of_sort(global, 0, global.len_b + 2);
}

void	insert_all(t_stack **a, t_stack **b, t_global global)
{
	while (*b)
	{
		rotation_instructions(a, b, global);
		global.target_node = find_cheapest_node(b);
		rotate_before_insert(a, b, global);
		push(b, a, 'a');
		global.len_a++;
		global.len_b--;
		// print_lst	(*a);
		// print_lst	(*b);
	}
}

static t_global *set_global(t_stack **a, int len)
{
	t_global	*global;
	
	global = malloc(sizeof(t_global));
	global->low = global->sorted[0];
	global->high = global->sorted[len - 1];
	global->len_a = 2;
	global->len_b = len - 2;
	global->a_lst = a;
	global->b_lst = NULL;
	global->sorted = int_array_sorted(a, len);
}

void	sort_algo(t_stack **a, t_stack **b, int len)
{
	t_global	*global;

	global = set_global( a, len);
	pre_sort_to_b(*global);
	insert_all(a, b, *global);
}

/* ************************************************************************** */

/*
// TEST EVERYTHING

	should test everything in insert_all ../insert_to_a
	- rotation_instructions
		-find_insertion_point
	- find_cheapest_node
		- is_cheaper
		- calculate_cost
	- rotate_before_insert
*/