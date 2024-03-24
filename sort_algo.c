/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:59:03 by noam              #+#    #+#             */
/*   Updated: 2024/03/23 12:22:04 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "utils/node_utils/node_utils.c"
// #include "utils/str_utils/ft_atol.c"
// #include "utils/str_utils/ft_split.c"
// #include "utils/moving_utils/push_to.c"
// #include "utils/moving_utils/rr_rrr_ss.c"
// #include "utils/moving_utils/swap_rotate_revrotate.c"
// #include "int_array_sorted.c"
// #include "insert_to_a/rotate_before_insert.c"
// #include "insert_to_a/find_cheapest.c"
// #include "insert_to_a/rotation_instructions.c"
// #include "test/utils_test.c"
// #include "go_to_min_node.c"
// #include "utils/stack_comparing_utils.c" 

#include "push_swap_header.h"

void	pre_sort_to_b(t_stack **a, t_stack **b, t_global *global)
{
	t_stack	*tmp;

	tmp = (*a)->prev;
	while ((*a) != tmp)
	{
		if ((*a)->content == global->high || (*a)->content == global->low)
			rotate(a, 'a', global);
		else
			push(a, b, 'b', global);
	}
	if ((*a)->content == global->high || (*a)->content == global->low)
		rotate(a, 'a', global);
	else
		push(a, b, 'b', global);
}

void	insert_all(t_stack **a, t_stack **b, t_global *global)
{
	while (*b)
	{
		rotation_instructions(a, b, global);
		// printf("b->a_rot = %d b->b_rot = %d\n", (*b)->a_rot, (*b)->b_rot);
		global->target_node = find_cheapest_node(b);
		rotate_before_insert(a, b, global);
		push(b, a, 'a', global);
		// print_lst(*a);
		// print_lst(*b);

		// printf("len a %d len b %d\n", global->len_a, global->len_b);
	}
}

t_global	*init_global(t_stack **a, int len)
{
	t_global	*global;

	global = malloc(sizeof(t_global));
	global->sorted = int_array_sorted(a, len);
	global->low = global->sorted[0];
	global->high = global->sorted[len - 1];
	global->len_a = len;
	global->len_b = 0;
	global->nb_ops = 0;
	global->debug = 0;
	return (global);
}

void	sort_algo(t_stack **a, t_stack **b, t_global *global)
{
	pre_sort_to_b(a, b, global);
	// print_lst(b);
	insert_all(a, b, global);
	go_to_min_node(a, global);
	print_lst(*a);
	print_lst(*b);
	// printf("nb of total ops = %d\n", global->nb_ops);
}

/* ************************************************************************** */
/*

int	main(void)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	int len = 6;

	t_global	*global;

	char *arg[] = { "9", "20", "4", "8", "10", "16",  NULL};
	shuffle(*arg, 6);
	fillstack(&a, arg,len);	
	sort_algo(&a, &b, len);
	
	// global = init_global( &a, len);
	// printf("%d\n", find_low(a, *global));
	// go_to_min_node(&a, *global);
	// find_low(&a, *global);
	// go_to_min_node(&a, *global);
	
	// global = init_global( &a, len);
	// global.len_a=3;
	// global.len_b=1;
	// char *arg1[] = {"3","2", NULL};
	// fillstack(&b, arg1,2);	
	// print_lst(a);
	// print_lst(b);
	// insert_all(&a, &b, *global);
	print_lst(a);
	print_lst(b);
	printf("is sorted %d\n", stack_is_sorted(&a));
	// sort_algo(&a, &b, len);
	// print_lst(a);
}
 */

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