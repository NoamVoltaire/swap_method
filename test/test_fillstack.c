#include "../utils/node_utils.c"
#include "../utils/str_utils/ft_atol.c"
// #include "../push_swap_header.h"

#include <stdio.h>

int main(void)
{
	t_stack *node;
	printf("%d ",new_node(1, 0)->content == 1);
	printf("%d ",new_node(2, 0)->content == 2);
	printf("\n");
	// return (0);


	char *array[5] = {"1", "2", "3", "4", "5"}; 

	t_stack *a;
	a = NULL;
	fillstack(&a, array, 5);
	printf("%d ", a->content ==1);
	a = a->next;
	printf("%d ", a->content ==2);
	a = a->next;
	printf("%d ", a->content ==3);
	a = a->next;
	printf("%d ", a->content ==4);
	a = a->next;
	printf("%d ", a->content ==5);
	a = a->next;
	printf("%d ", a->content ==1);
	printf("\n");

}
