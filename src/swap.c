/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:12:43 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/09/11 17:46:52 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*(*head): The expression (*head) is used to ensure that the 
value of *head is treated as a single entity
before accessing its properties (such as next, prev).*/
void	swap(t_stack **head)
{
	if (!*head || !head)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack **a, bool flag)
{
	swap(a);
	if (!flag)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, bool flag)
{
	swap(b);
	if (!flag)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, bool flag)
{
	swap(a);
	swap(b);
	if (!flag)
		write(1, "ss\n", 3);
}
