#include "../utils/node_utils.c"
#include "../utils/str_utils/ft_atol.c"
// #include "../push_swap_header.h"

#include <stdio.h>

int main(void)
{

/***************************************************************************/

	t_stack *node;
	printf("%d ",new_node(1)->content == 1);
	printf("%d ",new_node(2)->content == 2);
	printf("\n");
	// return (0);

/***************************************************************************/

	char *array_of_two[2] = {"1", "2"};
	t_stack *two;
	two = NULL;

	fillstack(&two, array_of_two, 2);
	printf("%d ", (two->content == 1 && two->next->content == 2 && two->prev->content == 2));
	printf("\n");

/***************************************************************************/

	char *array[5] = {"1", "2", "3", "4", "5"}; 
	t_stack *a;
	a = NULL;

	fillstack(&a, array, 5);
	printf("%d ", (a->content ==1 && a->next->content ==2 && a->prev->content ==5));
	a = a->next;
	printf("%d ", a->content ==2 && a->next->content ==3 && a->prev->content ==1);
	a = a->next;
	printf("%d ", a->content ==3 && a->next->content ==4 && a->prev->content ==2);
	a = a->next;
	printf("%d ", a->content ==4 && a->next->content ==5 && a->prev->content ==3);
	a = a->next;
	printf("%d ", a->content ==5 && a->next->content ==1 && a->prev->content ==4);
	a = a->next;
	printf("%d ", a->content == 1 && a->next->content == 2 && a->prev->content == 5);
	printf("\n");

}
