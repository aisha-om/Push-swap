/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   adaptive.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By:  aabufarw <aabufarw@student.42.fr>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/25 12:09:29 by  aabufarw        #+#    #+#              */
/*   Updated: 2026/11/25 12:37:58 by  aabufarw       ###   ########.fr        */
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

void	adaptive_sort(t_stack **a, t_stack **b)
{
	float	disorder;
	int		size;

	size = stack_size(*a);
	if (size <= 1)
		return ;
	disorder = compute_disorder(a);
	if (disorder < 0.2f)
		//simple sort
	else if (disorder < 0.5f)
		//medium sort
	else
		//complex sort
}
