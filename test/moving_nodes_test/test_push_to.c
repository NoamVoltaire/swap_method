#include "../../utils/moving_utils/push_to.c"
#include "../../utils/node_utils/node_utils.c"
#include "../../utils/str_utils/ft_split.c"
#include "../../utils/str_utils/ft_atol.c"
#include "../../utils/moving_utils/rr_rrr_ss.c"
#include "../../utils/moving_utils/swap_rotate_revrotate.c"


static int	iterate_and_check(t_stack *a, t_stack *b,
			t_stack *good_a, t_stack *good_b,
			int good_len_a, int good_len_b)
{
	t_stack *tmp_head_mark_a;
	t_stack *tmp_head_mark_b;
	// t_stack *tmp_head_mark_good_a;
	// t_stack *tmp_head_mark_good_b;
	int len_a = 0;
	int len_b = 0;


	tmp_head_mark_a = a;
	tmp_head_mark_b = b;
	// tmp_head_mark_good_a = good_a;
	// tmp_head_mark_good_b = good_b;
	if (a == NULL && good_a == NULL)
	{
		printf("1\n");
	}
	else
	{

		if (a && a->content == good_a->content
			&& a->next->content == good_a->next->content
			&& a->prev->content == good_a->prev->content)
		{
				printf("1 ");
				len_a++;
		}
		else
			printf("0 ");

		a = a->next;
		good_a = good_a->next;
		while (a && a->content != tmp_head_mark_a->content)
		{
			printf("%d ", a->content == good_a->content
				&& a->next->content == good_a->next->content
				&& a->prev->content == good_a->prev->content);
			a = a->next;
			good_a = good_a->next;
			len_a++;
		}
		printf("\n");

	}

	if (b == NULL && good_b == NULL)
	{
		printf("1\n");
	}
	else
	{
	if (b && b->content == good_b->content
		&& b->next->content == good_b->next->content
		&& b->prev->content == good_b->prev->content)
	{
			printf("1 ");
			len_b++;
	}
	else
		printf("0 ");

	b = b->next;
	good_b = good_b->next;
	while (b && b->content != tmp_head_mark_b->content)
	{
		printf("%d ", b->content == good_b->content
			&& b->next->content == good_b->next->content
			&& b->prev->content == good_b->prev->content);
		b = b->next;
		good_b = good_b->next;
		len_b++;
	}
	printf("\n");
	}
	return (len_a == good_len_a && len_b == good_len_b);
}
	




int	main(void)
{
	t_stack	*a;
	t_stack	*b;
	t_stack *good_a;
	t_stack *good_b;

	fillstack(&a, ft_split("1 2 3 4 5", ' '), 5);
	fillstack(&b, ft_split("6 7 8 9 10", ' '), 5);
	
		push(&a, &b, 'b');
	fillstack(&good_a, ft_split("2 3 4 5", ' '), 4);
	fillstack(&good_b, ft_split("1 6 7 8 9 10", ' '), 6);
		printf("%d \n", iterate_and_check(a, b, good_a, good_b, 4, 6)); 
	free_stack(&good_b);
	free_stack(&good_a);

		push(&b, &a, 'a');
	fillstack(&good_a, ft_split("1 2 3 4 5", ' '), 5);
	fillstack(&good_b, ft_split("6 7 8 9 10", ' '), 5);
		printf("%d \n", iterate_and_check(a, b, good_a, good_b, 5, 5));
	free_stack(&good_a);
	free_stack(&good_b);

		push(&b, &a, 'a');
		push(&b, &a, 'a');
		push(&b, &a, 'a');
		push(&b, &a, 'a');
	fillstack(&good_a, ft_split("9 8 7 6 1 2 3 4 5", ' '), 9);
	fillstack(&good_b, ft_split("10", ' '), 1);
		printf("%d \n", iterate_and_check(a, b, good_a, good_b, 9, 1));
	free_stack(&good_a);
	free_stack(&good_b);

	push(&b, &a, 'a');
	fillstack(&good_a, ft_split("10 9 8 7 6 1 2 3 4 5", ' '), 10);
	// fillstack(&good_b, ft_split("", ' '), 0);
		printf("%d \n", iterate_and_check(a, b, good_a, good_b, 10, 0));
		// printf("%d", b == NULL);

	free_stack(&good_a);
	free_stack(&good_b);



// 	swap(&a, 'a');
// 	push(&a, &b, 'b');
// 	//1 3 and 2 6
// 	rr(&a, &b); 
// 	// 3 4 5 and 6 7 8
// 	rotate(&a, 'a');
// 	// 4 5 1 and 6 7 8 
// 	// rotate(&a, 'a');
// 	push(&a, &b, 'b');
// 	// 5 and 4 6
// 	rrr(&a, &b);
// 	rotate(&b, 'b');
// 	// 1 and 7 8 9
// 	push(&b, &a, 'a');
// 	// 7 1 and 8 9
// 	rr(&a, &b);
// 	push(&b, &a, 'a');
// 	fillstack(&good_a, ft_split("9 1 3 5 7", ' '), 5);
// 	fillstack(&good_b, ft_split("10 8 6 4 2", ' '), 5);
// 	printf("%d ", iterate_and_check(a, b, good_a, good_b, 5, 5));
// 	free_stack(&good_a);
// 	free_stack(&good_b);


}