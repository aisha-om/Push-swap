/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   compute_disorder.c                                :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By:  aabufarw <aabufarw@student.42.fr>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/25 10:54:53 by  aabufarw        #+#    #+#              */
/*   Updated: 2026/11/25 11:06:49 by  aabufarw       ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*compare;
	float	mistakes;
	float	total_pairs;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (0.0f);
	mistakes = 0;
	total_pairs = 0;
	current = *stack_a;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			total_pairs++;
			if (current->index > compare->index)
				mistakes++;
			compare = compare->next;
		}
		current = current->next;
	}
	return (mistakes / total_pairs);
}
