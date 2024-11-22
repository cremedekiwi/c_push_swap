/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:16:48 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/25 19:05:57 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack **head, t_stack **tail)
{
	t_stack	*aux;

	if (*head == NULL || *tail == NULL || *head == *tail)
		return ;
	insert_end(tail, (*head)->nb);
	aux = (*head)->next;
	remove_node(*head);
	*head = aux;
}

void	ra(t_stacks *stacks)
{
	rotate(&stacks->head_a, &stacks->tail_a);
	ft_printf("ra\n");
}

void	rb(t_stacks *stacks)
{
	rotate(&stacks->head_b, &stacks->tail_b);
	ft_printf("rb\n");
}
