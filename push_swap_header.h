/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_header.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:03:20 by noam              #+#    #+#             */
/*   Updated: 2024/03/18 03:48:10 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_HEADER_H
# define PUSH_SWAP_HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


typedef struct s_node
{
	long			content;
	int				index;
	int				position;
	int				a_rot;
	int 			b_rot;

	int				above_median;
	int				cheapest;

	struct s_node	*node;
	struct s_node	*next;
	struct s_node	*prev;
}	t_stack;


	// int	start;
	// int	end;
	// int	mid;
	// int	second_mid;
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

// TEST UTILITIES
void	print_lst(t_stack *lst);

//	utils
void	error(t_stack *a, t_stack *b);

//	str utils
char	**ft_split(char *str_words, char sep);
long	ft_atol(const char *digit_str);
int		is_digit(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//	node utils
t_stack	*new_node(int content);
void	add_to_front(t_stack **lst, t_stack *new);
void	fillstack(t_stack **a, char **array, const int len);
void	free_stack(t_stack **lst);

//	nodes move (sa sb ra rb rra rrb)
void	swap(t_stack **lst, char stack);
void	rotate(t_stack **lst, char stack);
void	reverse_rotate(t_stack **lst, char stack);

void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);

//	parsing utils
void	check_input(char **arg);

//start sort


#endif  