/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:44:14 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/25 19:07:36 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrotate(t_stack **head, t_stack **tail)
{
	t_stack	*aux;

	if (*head == NULL || *tail == NULL || *head == *tail)
		return ;
	insert_beginning(head, (*tail)->nb);
	aux = (*tail)->prev;
	remove_node(*tail);
	*tail = aux;
}

void	rra(t_stacks *stacks)
{
	rrotate(&stacks->head_a, &stacks->tail_a);
	ft_printf("rra\n");
}

void	rrb(t_stacks *stacks)
{
	rrotate(&stacks->head_b, &stacks->tail_b);
	ft_printf("rrb\n");
}

void	rrr(t_stacks *stacks)
{
	rrotate(&stacks->head_a, &stacks->tail_a);
	rrotate(&stacks->head_b, &stacks->tail_b);
	ft_printf("rrr\n");
}
