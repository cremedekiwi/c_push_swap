/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:59:37 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/25 19:44:23 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	insert_beginning(t_stack **head, long value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
	{
		exit(3);
		return ;
	}
	new_node->nb = value;
	new_node->prev = NULL;
	new_node->next = *head;
	(*head)->prev = new_node;
	*head = new_node;
}

void	insert_end(t_stack **tail, long value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
	{
		exit(4);
		return ;
	}
	new_node->nb = value;
	new_node->next = NULL;
	new_node->prev = *tail;
	(*tail)->next = new_node;
	*tail = new_node;
}

void	remove_node(t_stack *node)
{
	if (node->prev != NULL)
		node->prev->next = node->next;
	if (node->next != NULL)
		node->next->prev = node->prev;
	free(node);
}
