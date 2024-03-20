#include "utils/node_utils/node_utils.c"
#include "utils/str_utils/ft_atol.c"
#include "utils/str_utils/ft_split.c"
#include "utils/moving_utils/push_to.c"
#include "utils/moving_utils/rr_rrr_ss.c"
#include "utils/moving_utils/swap_rotate_revrotate.c"
#include "int_array_sorted.c"
#include "insert/rotate_before_insert.c"
#include "insert/find_cheapest.c"
#include "insert/rotation_instructions.c"


void	print_lst(t_stack *lst)
{
	// int i = 6; // 
	
	if (!lst)
	{
		printf("empty list\n");	
		return ;
	}
	t_stack *tmp = lst;
	printf("\033[0m%ld ", lst->content);
	lst = lst->next;
	while (tmp != lst)
	{
		printf("\033[0m%ld ", lst->content);
		lst = lst->next;
	}
	printf("\n");
}


typedef struct{
	int high;
	int low;
	int len_a;
	int len_b;
	int *sorted;
	int nb_ops;
	t_stack *target_node;
	char debug_mode;
} global_struct;

void pre_sort_to_b(t_stack **a, t_stack **b, global_struct global)
{
	t_stack *tmp;

	tmp = (*a)->prev;
	while ((*a) != tmp){
		if((*a)->content == global.high || (*a)->content == global.low)
		{
			rotate(a, 'a');
		}
		else
		{
			push(a, b, 'b');
		}
	}
}

int find_insertion_point(int e, t_stack *a, int len_a)
{
	int j = 0;
	t_stack *tmp = a;
	
	while (tmp->content < e || tmp->prev->content > e)
	{
		j++;
		tmp = tmp->next;
	}
	if (j > len_a / 2)
		j = (j - len_a / 2) * -1;
	return (j);
}

// void	rotate_before_insert(t_stack **a, t_stack **b, global_struct global)
// {
// 	while (global.target_node->a_rot > 0 && global.target_node->b_rot > 0)
// 	{
// 		rr(a, b);
// 		global.target_node->a_rot--;
// 		global.target_node->b_rot--;
// 	}
// 	while (global.target_node->a_rot < 0 && global.target_node->b_rot < 0)
// 	{
// 		rrr(a, b);
// 		global.target_node->a_rot++;
// 		global.target_node->b_rot++;
// 	}
// 	while (global.target_node->a_rot > 0)
// 	{
// 		rotate(a, 'a');
// 		global.target_node->a_rot--;
// 	}
// 	while (global.target_node->a_rot < 0)
// 	{
// 		reverse_rotate(a, 'a');
// 		global.target_node->a_rot++;
// 	}
// 	while (global.target_node->b_rot > 0)
// 	{
// 		rotate(b, 'b');
// 		global.target_node->b_rot--;
// 	}
// 	while (global.target_node->b_rot < 0)
// 	{
// 		reverse_rotate(b, 'b');
// 		global.target_node->b_rot++;
// 	}
// 	// printf("	ra = %d, rb  = %d\n", global.target_node->a_rot, global.target_node->b_rot);
		
// }

int	is_cheaper(t_stack **node, t_stack **target_node)
{
	// printf("	rot_a = %d, rot_b  = %d\n", (*node)->a_rot, (*node)->b_rot);
	int node_cost;
	// int target_cost;
	int arot = (*node)->a_rot;
	int brot = (*node)->b_rot;
	int tarot = (*target_node)->a_rot;
	int tbrot = (*target_node)->b_rot;
	// targettmp = *target_node;
	// nodetmp = *node;

	// if (arot < 0)
	// 	arot *= -1;
	arot = (arot < 0) ? -arot : arot;
	brot = (brot < 0) ? -brot : brot;
	// if (brot < 0)
	// 	brot *= -1;
	if (arot > brot)
		node_cost = arot - brot;
	else
		node_cost = brot - arot;
	// node_cost = arot + brot - arot - brot;

	// if (tarot < 0)
	// 	tarot *= -1;
	// if (tbrot < 0)
	// 	tbrot *= -1;
	tarot = (tarot < 0) ? -tarot : tarot;
	tbrot = (tbrot < 0) ? -tbrot : tbrot;
	if (tarot > tbrot)
		return (node_cost < (tarot - tbrot));
	else
		return (node_cost < (tbrot - tarot));

	// if (tarot > tbrot)
	// 	target_cost = tarot - tbrot;
	// else
	// 	target_cost = tbrot - tarot;

	// if (nodetmp->a_rot < 0)
	// 	nodetmp->a_rot *= -1;
	// if (nodetmp->b_rot < 0)
	// 	nodetmp->b_rot *= -1;
	// if (nodetmp->a_rot > nodetmp->b_rot)
	// 	node_cost = nodetmp->a_rot - nodetmp->b_rot;
	// else
	// 	node_cost = nodetmp->b_rot - nodetmp->a_rot;


	// if  (targettmp->a_rot < 0)
	// 	targettmp->a_rot *= -1;
	// if (targettmp->b_rot < 0)
	// 	targettmp->b_rot *= -1;
	// if (targettmp->a_rot > targettmp->b_rot)
	// 	target_cost = targettmp->a_rot - targettmp->b_rot;
	// else
	// 	target_cost = targettmp->b_rot - targettmp->a_rot;

//  printf("node_cost %d, target_node_cost %d\n", node_cost, target_cost);
	// return (node_cost < target_cost);

}

void go_to_min_node(t_stack **a, global_struct global)
{
	t_stack	*tmp;
	int		min;
	int		j;

	tmp = (*a);
	min = global.sorted[0];
	j = 0;
	while (tmp->content != min)
	{
		j++;
		tmp = tmp->next;
	}
	if (j > global.len_a / 2)
		j = (j - global.len_a / 2) * -1;
	while (j > 0)
	{
		rotate(a, 'a');
		j--;
	}
	while (j < 0)
	{
		reverse_rotate(a, 'a');
		j++;
	}
}

void	rotation_instructions(t_stack **a, t_stack **b, global_struct global)
{
	t_stack	*tmp;
	int		rot;

	tmp = (*b);
	rot = 0;
	(*b)->a_rot = find_insertion_point((*b)->content, *a, global.len_a);
	(*b)->b_rot = rot++;
	(*b) = (*b)->next;
	while ((*b) != tmp)
	{
		(*b)->a_rot = find_insertion_point((*b)->content, *a, global.len_a);
		if (rot > global.len_b / 2)
			(*b)->b_rot = (rot - global.len_b / 2) * -1;
		else
			(*b)->b_rot = rot;
		rot++;
		(*b) = (*b)->next;
	}
}

t_stack	*find_cheapest_node(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*cheapest;

	tmp = *b;
	cheapest = *b;
	tmp = tmp->next;
	while (tmp != *b)
	{
		if (is_cheaper(&tmp, &cheapest))
		{
			cheapest = tmp;
			// printf("cheaper\n");
		}
		tmp = tmp->next;
	}
	return (cheapest);
}

void insert_all(t_stack **a, t_stack **b, global_struct global)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		rot;

	tmp_a = (*a);
	while (*b)
	{
	rotation_instructions(a, b, global);
	// rot = 0;
	// 	tmp_b = (*b);
	// 	(*b)->a_rot = find_insertion_point((*b)->content, *a, global.len_a);
	// 	(*b)->b_rot = rot++;
	// 	(*b) = (*b)->next;
	// 	while ((*b) != tmp_b)
	// 	{
	// 		// prin
	// 		(*b)->a_rot = find_insertion_point((*b)->content, *a, global.len_a);
	// 		if (rot > global.len_b / 2)
	// 			(*b)->b_rot = (rot - global.len_b / 2) * -1;
	// 		else
	// 			(*b)->b_rot = rot;
	// 		rot++;
	// 		(*b) = (*b)->next;
	// 	}

		global.target_node = find_cheapest_node(b);
		// global.target_node = *b;
		// (*b) = (*b)->next;
		// while ((*b) != tmp_b)
		// {
		
		// // printf("A	ra = %d, rb  = %d\n", (*b)->a_rot, (*b)->b_rot);
		// 	if (is_cheaper(b, &global.target_node))
		// 		// printf("cheaper\n");
		// // printf("A	ra = %d, rb  = %d\n", (*b)->a_rot, (*b)->b_rot);
		// // printf("B	ra = %d, rb  = %d\n", global.target_node->a_rot, global.target_node->b_rot);
		// 	if (is_cheaper(b, &global.target_node))
		// 		global.target_node = *b;

		// 	(*b) = (*b)->next;
		// }
		// return ;
		// printf("B	ra = %d, rb  = %d\n", global.target_node->a_rot, global.target_node->b_rot);
		rotate_before_insert(a, b, global);
		push(b, a, 'a');
		global.len_a++;
		global.len_b--;
		print_lst	(*a);
		print_lst	(*b);
	}
}

// void insert_all(t_stack **a, t_stack **b, global_struct global)
// {
// 	t_stack *tmp;
// 	int j;
// 	int ra;
// 	int rb;
// 	int rra;
// 	int rrb;

// 	tmp = (*b)->prev;
	
// 	while((*b) != tmp)
// 	{
// 		ra = find_insertion_point((*b)->content, *a);
// 		if (ra > global.len_a / 2)
// 		{
// 			rra = global.len_a / 2 - ra;
// 			ra = 0;
// 		}
		
// 		// while (j >= 0)
// 		// {
// 		// 	rotate(a, 'a');
// 		// 	j--;
// 		// }
// 		// push(b, a, 'b');
// 	}
// 	j = find_insertion_point((*b)->content, *a);
// 	while (j >= 0)
// 	{
// 		rotate(a, 'a');
// 		j--;
// 	}
// 	push(b, a, 'b');
// }

int	main(void)
{

	global_struct global;

	t_stack *a;
	t_stack	*b;

	b= NULL;
	int len = 5;
	char *arg[] = {"4", "3", "2", "0", "1", NULL};

	global.sorted = int_array_sorted(arg, len);
	global.high= global.sorted[len-1];
	global.low = global.sorted[0];
	global.nb_ops = 0;
	global.debug_mode = 1;
	global.len_a = 2;
	global.len_b = len - 2;
	

	fillstack(&a, arg, 5);
	pre_sort_to_b(&a, &b, global);
	insert_all(&a, &b, global);
	go_to_min_node(&a, global);
	print_lst(a);
	print_lst(b);
	printf("nb_ops = %d\n", global.nb_ops);
}


/* ************************************************************************** */
//	TODO

//	1. make a function that goes to min node after it's been pushed to b | OK

//	2. tidy up insert_all by making a functions that  | OK
//		- puts the number of rots to be made to insert the node at the right place
//		- finds the cheapest node to insert in the list an puts it in a global variable

//	3. make is_cheaper smaller with this
//		- arot = (arot < 0) ? -arot : arot;		(idk if it's norminette compliant)

//	4. make a rotate before insert smaller individual funcitons (make a new file duh)
// 		- 4 functions in total
// 			- rotate_both
//			- rev_rotate_both
//			- rotate_single(t_stack **stack, char stack_name, int *rot

// arot = (arot < 0) ? -arot : arot;

