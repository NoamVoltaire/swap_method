#include "../push_swap_header.h"

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
		// printf("\033[1;31m%ld ", lst->prev->content);
		// printf("\033[1;32m%ld ", lst->next->content);
		// f(lst->index);
		// printf("\n");
		lst = lst->next;
	while (tmp->content != lst->content)
	{
		printf("\033[0m%ld ", lst->content);
		// printf("\033[1;31m%ld ", lst->prev->content);
		// printf("\033[1;32m%ld ", lst->next->content);
		// f(lst->index);
		// printf("\n");
		lst = lst->next;
	}
	printf("\n");
}