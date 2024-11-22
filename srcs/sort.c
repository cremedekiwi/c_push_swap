/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:06:30 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/25 23:45:04 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_stacks *stacks)
{
	long	a;
	long	b;

	a = stacks->head_a->nb;
	b = stacks->head_a->next->nb;
	if (a > b)
		sa(stacks);
}

void	sort_three(t_stacks *stacks)
{
	long	a;
	long	b;
	long	c;

	a = stacks->head_a->nb;
	b = stacks->head_a->next->nb;
	c = stacks->head_a->next->next->nb;
	if (a > b && b > c)
	{
		sa(stacks);
		rra(stacks);
	}
	else if (a > c && c > b)
		ra(stacks);
	else if (b > a && a > c)
		rra(stacks);
	else if (c > a && a > b)
		sa(stacks);
	else if (b > c && c > a)
	{
		sa(stacks);
		ra(stacks);
	}
}

// i divide my stack by 2, and check the optimal route to rotate (ra or rra)
void	optimal_rotation(int max_pos, int size, t_stacks *stacks)
{
	if (max_pos <= size / 2)
	{
		while (max_pos-- > 0)
			ra(stacks);
	}
	else
	{
		while (size - max_pos++ > 0)
			rra(stacks);
	}
	pb(stacks);
}

// find the highest number to push to b
void	pb_highest(t_stacks *stacks)
{
	t_stack	*max;
	t_stack	*curr;
	int		max_pos;
	int		size;
	int		i;

	if (stacks->head_a == NULL)
		return ;
	max = stacks->head_a;
	curr = stacks->head_a->next;
	max_pos = 0;
	size = 1;
	i = 1;
	while (curr != NULL)
	{
		if (curr->nb > max->nb)
		{
			max = curr;
			max_pos = i;
		}
		curr = curr->next;
		i++;
		size++;
	}
	optimal_rotation(max_pos, size, stacks);
}

// sort number greater than 3, but too many operations for 100 and 500
void	sort_n(t_stacks *stacks, int n)
{
	int	count;

	count = n - 3;
	while (count > 0)
	{
		pb_highest(stacks);
		count--;
	}
	sort_three(stacks);
	count = n - 3;
	while (count > 0)
	{
		pa(stacks);
		ra(stacks);
		count--;
	}
}
