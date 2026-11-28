/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   medium_algo.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By:  aabufarw <aabufarw@student.42.fr>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/25 16:45:58 by  aabufarw        #+#    #+#              */
/*   Updated: 2026/11/25 20:53:07 by  aabufarw       ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chunk_size(int n)
{
	int	i;

	i = 1;
	while (i <= n / i)
	{
		if (i * i == n)
			return (i);
		i++;
	}
	return (i);
}

static void	push_chunk(t_stack **a, t_stack **b, int low, int size)
{
	int	index;
	int	count;

	count = 0;
	while (*a && count < size)
	{
		index = (*a)->index;
		if (index >= low && index < low + size)
		{
			// Push B
			if (index < low + size / 2)
				// Rotate B
			count++;
		}
		else
			// Rotate A
	}
}

static int	find_position(t_stack *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack && stack->index != index)
	{
		stack = stack->next;
		pos++;
	}
	return (pos);
}

static void	move_to_top(t_stack **b, int pos, int len)
{
	if (pos <= len / 2)
	{
		while (pos > 0)
		{
			// Rotate B
			pos--;
		}
	}
	else
	{
		while (pos < len)
		{
			// Reverse rotate B
			pos++;
		}
	}
}

void	medium_sort(t_stack **a, t_stack **b, int n, t_bench *bench)
{
	int	size;
	int	low;
	int	count;

	bench->algo = "Medium Sort";
	if (n <= 1)
		return ;
	size = chunk_size(n);
	low = 0;
	while (low < n)
	{
		count = size;
		if (low + size > n)
			count = n - low;
		push_chunk(a, b, low, count);
		low += count;
	}
	while (n > 0)
	{
		move_to_top(b, find_position(*b, n - 1), n);
		// Push A
		n--;
	}
}
