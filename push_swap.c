/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:36:26 by noam              #+#    #+#             */
/*   Updated: 2024/03/21 19:12:31 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"

// void	minisort(char **args, int len)
// {
// 	if (len == 2)
// 	{
// 		if (ft_atoi(args[0]) > ft_atoi(args[1]))
// 			write(1, "sa\n", 3);
// 	}
// 	if (len == 3)
// }

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

void	initialize(char **arg, int len)
{
	t_stack		*a;
	t_stack		*b;
	t_global	*global;
	// int			*sorted;

	b = NULL;
	fillstack(&a, arg, len);
	// sorted = int_array_sorted(a, len);
	global = init_global(&a, len);
	sort_algo(&a, &b, global);
	printf("is sorted = %d\n", stack_is_sorted(&a));
	printf("nb of total ops = %d\n", global->nb_ops);
}

int	main(int ac, char **av)
{
	char	**args;
	int		len;

	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = av + 1;
	check_input(args);
	len = count_args(args) + 1;
	if (len == 1)
		return (0);
	// if (len < 4)
	// 	minisort(args, len);
	initialize(args, len);
	printf("len = %d\n", len);
	// while (len--)
	// 	printf("av = %s\n", *args++);
}

