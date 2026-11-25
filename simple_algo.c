/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   simple_algo.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By:  aabufarw <aabufarw@student.42.fr>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/23 21:24:21 by  aabufarw        #+#    #+#              */
/*   Updated: 2026/11/25 13:39:20 by  aabufarw       ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_min(t_stack *a)
{
	t_stack	*min;

	min = a;
	while (a)
	{
		if (a->index < min->index)
			min = a;
		a = a->next;
	}
	return (min);
}

static void	move_min_to_top(t_stack **a, t_stack *min)
{
	int		pos;
	int		size;
	t_stack	*current;

	pos = 0;
	size = stack_size(*a);
	current = *a;
	while (current != min)
	{
		pos++;
		current = current->next;
	}
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			// ra
		;
	}
	else
	{
		while (pos++ < size)
			// rra
		;
	}
}

void	simple_sort(t_stack **a, t_stack **b)
{
	t_stack	*min;

	while (*a)
	{
		min = find_min(*a);
		move_min_to_top(a, min);
		// pb
	}
	while (*b)
		// pa
	;
}
