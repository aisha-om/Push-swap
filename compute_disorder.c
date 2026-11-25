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
	t_stack	*next;
	float	mistakes;
	float	total_pairs;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (0.0f);
	mistakes = 0;
	total_pairs = 0;
	current = *stack_a;
	while (current)
	{
		next = current->next;
		while (next)
		{
			if (current->index > next->index)
				mistakes++;
			total_pairs++;
			next = next->next;
		}
		current = current->next;
	}
	return (mistakes / total_pairs);
}
