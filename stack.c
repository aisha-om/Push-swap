/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   stack.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: aabufarw <aabufarw@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/28 12:35:14 by aabufarw         #+#    #+#              */
/*   Updated: 2026/11/28 14:19:16 by aabufarw        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_new(t_stack **lst, int content)
{
	t_stack	*new;
	t_stack	*last;

	if (!lst)
		return ;
	new = (t_stack *) malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = content;
	new->next = NULL;
	if (!*lst)
	{
		new->prev = NULL;
		new->index = 0;
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
	new->prev = last;
	new->index = last->index + 1;
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*current;
	t_stack	*next;

	if (!lst || !(*lst))
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		current->value = 0;
		current->index = 0;
		free(current);
		current = next;
	}
	*lst = NULL;
}
