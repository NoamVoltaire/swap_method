/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:02:31 by noam              #+#    #+#             */
/*   Updated: 2024/05/09 16:10:27 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>
// #include <stdlib.h>
// #include "get_next_line/get_next_line.h"
#include "../push_swap_header.h"

int	compare_to_sorted(t_stack *a, char **args, int len)
{
	int		*sorted;
	int		i;
	t_stack	*tmp;

	fillstack(&tmp, args, len);
	sorted = int_array_sorted(&tmp, len);
	i = 0;
	while (a->content == sorted[i])
	{
		a = a->next;
		i++;
	}
	free(sorted);
	free_stack(&tmp);
	return (i == len);
}

char	**parse_n_check(int ac, char **av, int *is_mallocd)
{
	char	**args;

	if (ac <= 1)
		exit(0);
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		is_mallocd[0] = 1;
	}
	else
		args = av + 1;
	check_input(args, *is_mallocd);
	return (args);
}

int	main(int ac, char **av)
{
	char		**args;
	int			len;
	t_stack		*a_bonus;
	int			*mallocd;
	int			mall;

	a_bonus = NULL;
	mall = 0;
	mallocd = &mall;
	args = parse_n_check(ac, av, mallocd);
	len = count_args(args) + 1;
	fillstack(&a_bonus, args, len);
	read_and_exec(&a_bonus, len);
	if (compare_to_sorted(a_bonus, args, len))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a_bonus);
	if (mallocd)
		free_array(args);
}

/* ************************************************************************** */
/*

So, we would want uhhhh, 
while (still something to read in terminal) (line = get_next_line(0) != NULL)
	-stash_line = str_join (stash_line, line)


*/