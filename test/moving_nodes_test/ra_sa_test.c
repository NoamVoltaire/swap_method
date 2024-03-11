#include "../../utils/node_utils.c"
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

int main(void)
{

	t_stack	*a;
	t_stack	*b;
	t_stack *good_a;
	t_stack *good_b;

	fillstack(&a, ft_split("1 2 3 4 5", ' '), 5);
	fillstack(&b, ft_split("6 7 8 9 10", ' '), 5);

		swap(&a, 'a');
		reverse_rotate(&a, 'a');
		rotate(&b, 'b');
		swap(&b, 'b');
	fillstack(&good_a, ft_split("5 2 1 3 4", ' '), 5);
	fillstack(&good_b, ft_split("8 7 9 10 6", ' '), 5);
		printf("%d\n", iterate_and_check(a, b, good_a, good_b, 5, 5));

		rotate(&a, 'a');
		rotate(&a, 'a');
		rotate(&a, 'a');
		rotate(&a, 'a');
		rotate(&a, 'a');
	printf("%d\n", iterate_and_check(a, b, good_a, good_b, 5, 5));

	free_stack(&good_a);
	free_stack(&good_b);

}