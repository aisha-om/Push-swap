/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   simple_algo.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By:  aabufarw <aabufarw@student.42.fr>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/23 21:24:21 by  aabufarw        #+#    #+#              */
/*   Updated: 2026/11/25 20:55:36 by  aabufarw       ###   ########.fr        */
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

static int	min_position(t_stack *a, t_stack *min)
{
	int	pos;

	pos = 0;
	while (a != min)
	{
		pos++;
		a = a->next;
	}
	return (pos);
}

static void	move_min(t_stack **a, int pos)
{
	int	size;

	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			// ra
		;
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			// rra
		;
	}
}

void	simple_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*min;
	int		pos;

	bench->algo = "Simple Sort";
	while (*a)
	{
		min = find_min(*a);
		pos = min_position(*a, min);
		move_min(a, pos);
		// pb
	}
	while (*b)
		// pa
	;
}
