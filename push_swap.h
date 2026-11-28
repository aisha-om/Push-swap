/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: aabufarw <aabufarw@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/23 20:55:53 by aabufarw         #+#    #+#              */
/*   Updated: 2026/11/28 14:25:21 by aabufarw        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;
typedef struct s_bench
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		total;
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
void	ft_lstclear(t_stack **lst);
void	ft_lstadd_back_new(t_stack **lst, int content);
#endif
