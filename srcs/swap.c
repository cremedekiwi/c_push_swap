/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:11:38 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/25 19:09:21 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = (*head)->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->next = first;
	second->prev = first->prev;
	first->prev = second;
	*head = second;
}

void	sa(t_stacks *stacks)
{
	swap(&stacks->head_a);
	ft_printf("sa\n");
}

void	sb(t_stacks *stacks)
{
	swap(&stacks->head_b);
	ft_printf("sb\n");
}

void	ss(t_stacks *stacks)
{
	swap(&stacks->head_a);
	swap(&stacks->head_b);
	ft_printf("ss\n");
}
