/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   complex_algo.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By:  aabufarw <aabufarw@student.42.fr>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/25 17:09:35 by  aabufarw        #+#    #+#              */
/*   Updated: 2026/11/25 20:55:13 by  aabufarw       ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	max;
	int	bits;

	max = size - 1;
	bits = 0;
	while (max > 0)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
}

static void	sort_bit(t_stack **a, t_stack **b, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((*a)->index >> bit) & 1)
		{
			// ra
		}
		else
		{
			// pb
		}
		i++;
	}
	while (*b)
		// pa
	;
}

void	complex_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;
	int	bits;
	int	i;

	bench->algo = "Complex Sort";
	size = stack_size(*a);
	if (size <= 1)
		return ;
	bits = get_max_bits(size);
	i = 0;
	while (i < bits)
	{
		sort_bit(a, b, i, size);
		i++;
	}
}
