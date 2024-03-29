/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_header.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:03:20 by noam              #+#    #+#             */
/*   Updated: 2024/03/29 10:59:09 by noam             ###   ########.fr       */
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
	int				a_rot;
	int				b_rot;

	struct s_node	*next;
	struct s_node	*prev;
}	t_stack;

typedef struct s_info
{
	int		high;
	int		low;
	int		len_a;
	int		len_b;
	int		*sorted;
	int		nb_ops;
	int		debug;

	t_stack	*target_node;
}	t_global;

// TEST UTILITIES
// void		print_lst(t_stack *lst);

//	utils
void		error(char **array, int mallocd);
void		check_input(char **arg, int mallocd);
void		free_array(char **array);

//	str utils
char		**ft_split(char *str_words, char sep);
long		ft_atol(const char *digit_str);
int			is_digit(char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			count_args(char **argsss);

//	node utils
t_stack		*new_node(int content);
void		add_to_front(t_stack **lst, t_stack *new);
void		fillstack(t_stack **a, char **array, const int len);

void		go_to_min_node(t_stack **a, t_global *global);

int			next_node_is_bigger(t_stack *lst);
int			stack_is_sorted(t_stack **lst);

void		free_stack(t_stack **lst);

//	nodes move (sa sb ra rb rra rrb)
void		swap(t_stack **lst, char stack, t_global *global);
void		rotate(t_stack **lst, char stack, t_global *global);
void		reverse_rotate(t_stack **lst, char stack, t_global *global);
void		push(t_stack **lst, t_stack **dest,	char dest_name, t_global *glob);

void		rr(t_stack **a, t_stack **b, t_global *global);
void		rrr(t_stack **a, t_stack **b, t_global *global);
void		ss(t_stack **a, t_stack **b, t_global *global);

// int_array_sorted
int			*int_array_sorted(t_stack **a, int len);

// sort
t_global	*init_global(t_stack **a, int len);
void		start_sorting(t_stack **a, t_stack **b, t_global *global);
void		sort_three(t_stack **lst, char stack, t_global *global);

void		sort_algo(t_stack **a, t_stack **b, t_global *global);
void		pre_sort_to_b(t_stack **a, t_stack **b, t_global *global);
void		insert_all(t_stack **a, t_stack **b, t_global *global);

void		rotation_instructions(t_stack **a, t_stack **b, t_global *global);
t_stack		*find_cheapest_node(t_stack **b);
void		rotate_before_insert(t_stack **a, t_stack **b, t_global *global);

/*----------------------------------bonus------------------------------------*/
// utils
void		error_ko(char *line);
void		check_read_line(char *big_line);
char		*ft_strjoin(char *s1, char *s2);
// int			lst_len(t_stack *stack);


char		*get_next_line(int fd);
void		read_and_exec(t_stack **a, int len);
void		execute_commands(char **cmnds, t_stack **a, int len);



#endif  