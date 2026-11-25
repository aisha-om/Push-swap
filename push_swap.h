/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By:  aabufarw <aabufarw@student.42.fr>        #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/23 20:55:53 by  aabufarw        #+#    #+#              */
/*   Updated: 2026/11/25 22:28:58 by  aabufarw       ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;
typedef struct s_bench
{
	int	sa;
	// Count of sa operation
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
	// Total number of operations for all moves
	char	*algo;
	float	disorder;
	char	*complexity;
}	t_bench;

float	compute_disorder(t_stack **a);
int		stack_size(t_stack *stack);
void	adaptive_sort(t_stack **a, t_stack **b, t_bench *bench);
void	simple_sort(t_stack **a, t_stack **b, t_bench *bench);
void	medium_sort(t_stack **a, t_stack **b, int n, t_bench *bench);
void	complex_sort(t_stack **a, t_stack **b, t_bench *bench);
int		ft_strcmp(const char *s1, const char *s2);
#endif
