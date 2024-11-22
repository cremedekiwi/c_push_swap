/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:36:22 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/30 13:34:04 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// differents sorts by stack size (2, 3, 4 to 41, greater)
	// print_stack(stacks.head_a);
	// if (stacks.head_b != NULL)
	// {
	// 	ft_printf("\n");
	// 	print_stack(stacks.head_b);
	// }
int	main(int ac, char **av)
{
	t_stacks	stacks;
	int			parse_nb;

	init_stacks(&stacks);
	parse_nb = parse_argv(ac, av, &stacks);
	if (is_duplicate(&stacks))
		return (deallocate_stacks(&stacks), ft_error(), 1);
	if (parse_nb <= 0)
		return (1);
	if (!is_sorted(&stacks))
	{
		if (parse_nb == 2)
			sort_two(&stacks);
		else if (parse_nb == 3)
			sort_three(&stacks);
		else if (parse_nb > 3 && parse_nb < 41)
			sort_n(&stacks, parse_nb);
		else if (parse_nb >= 42)
			radix_sort(&stacks);
	}
	deallocate_stacks(&stacks);
	return (0);
}
