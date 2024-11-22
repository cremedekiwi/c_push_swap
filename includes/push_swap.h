/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:30:28 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/30 22:42:22 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

typedef struct s_stack
{
	long			nb;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*head_a;
	t_stack	*tail_a;
	t_stack	*head_b;
	t_stack	*tail_b;
}	t_stacks;

void	ft_error(void);
int		is_number(const char *str);
int		is_duplicate(t_stacks *stacks);
int		is_space(char c);
void	free_array(char **array);
void	deallocate(t_stack **head, t_stack **tail);
void	deallocate_stacks(t_stacks *stacks);
void	init_stacks(t_stacks *stacks);
void	first_value(t_stack **head, t_stack **tail, long value);
void	populate_stack(t_stacks *stacks, long nbr);
void	split_argv(char *arg, t_stacks *stacks, int *nb);
int		parse_argv(int ac, char **av, t_stacks *stacks);
void	insert_beginning(t_stack **head, long value);
void	insert_end(t_stack **tail, long value);
void	remove_node(t_stack *node);
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);
void	sort_two(t_stacks *stacks);
void	sort_three(t_stacks *stacks);
void	sort_n(t_stacks *stacks, int n);
long	get_max(t_stack *head);
int		stack_length(t_stack *head);
void	radix_sort(t_stacks *stacks);
void	print_stack(t_stack *head);
int		is_sorted(t_stacks *stacks);

#endif
