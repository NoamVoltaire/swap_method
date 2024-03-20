

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


typedef struct s_info
{
	int		high;
	int		low;
	int		len_a;
	int		len_b;
	int		*sorted;
	t_stack	**a_lst;
	t_stack	**b_lst;
	t_stack	*target_node;
}	t_global;

void	push_with_limits(t_global global, int start, int mid, int end)
{
	int pushes;

	pushes = mid - start;
	while (pushes--)
	{
		
	}
}

void	some_sort(t_global global, int start, int end)
{
	int		mid;
	// int		next_mid;

	mid = 0;
	// next_mid = 0;
	if (start >= end)
		return ;
	mid = (start + end) / 2;
	// next_mid = (mid + end) / 2;
	push_with_limits(global, start, mid, end);
	some_sort(global, mid, end);
}
void	pre_sort_to_b(t_global global)
{
	some_sort(global, 0, global.len_b + 2);
}
