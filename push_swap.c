/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:36:26 by noam              #+#    #+#             */
/*   Updated: 2024/05/10 13:03:50 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"

static	void	initialize_n_start(char **arg, int len)
{
	t_stack		*a;
	t_stack		*b;
	t_global	*global;

	b = NULL;
	fillstack(&a, arg, len);
	global = init_global(&a, len);
	start_sorting(&a, &b, global);
	free_stack(&a);
	free_stack(&b);
	free(global->sorted);
	free(global);
}

int	main(int ac, char **av)
{
	char	**args;
	int		len;
	int		is_mallocd;

	is_mallocd = 0;
	if (ac <= 1)
		return (0);
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		is_mallocd = 1;
	}
	else
		args = av + 1;
	check_input(args, is_mallocd);
	len = count_args(args) + 1;
	if (len == 1)
	{
		free_array(args);
		return (0);
	} // NEED FREE
	initialize_n_start(args, len);
	if (is_mallocd)
		free_array(args);
}


// SEE WHEN ARGS == NULL
// SEE ATOL CUZ 008 or 001 does weird things


/* ************************************************************************** */
/*
void	print_lst(t_stack *lst)
{
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
*/