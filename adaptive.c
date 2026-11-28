/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   adaptive.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By:  aabufarw <aabufarw@student.42.fr>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/25 12:09:29 by  aabufarw        #+#    #+#              */
/*   Updated: 2026/11/25 22:28:31 by  aabufarw       ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int		count;
	t_stack	*current;

	count = 0;
	current = stack;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void	adaptive_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;

	bench->algo = "Adaptive Sort";
	bench->disorder = compute_disorder(a);
	size = stack_size(*a);
	if (size <= 1 || bench->disorder == 0.0f)
		return ;
	if (bench->disorder < 0.2f)
	{
		bench->complexity = " (O(n²))";
		simple_sort(a, b, bench);
	}
	else if (bench->disorder < 0.5f)
	{
		bench->complexity = "O(n * (√n))";
		medium_sort(a, b, size, bench);
	}
	else
	{
		bench->complexity = "O(n log n)";
		complex_sort(a, b, bench);
	}
}
