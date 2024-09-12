/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:48:56 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/09/12 16:04:04 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

 bool	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}


t_stack *find_bigger(t_stack *stack)
{
	int bigger;
	t_stack *bigger_node;

	if(!stack)
		return (NULL);
	bigger = INT_MIN;
	while(stack)
	{
		if (stack->nbr > bigger)
		{
			bigger = stack->nbr;
			bigger_node = stack;
		}
		stack = stack->next;
	}
	return (bigger_node);
}

void	sort_three(t_stack **a)
{
	t_stack	*bigger_node;
	
	bigger_node = find_bigger(*a);
	if(*a == bigger_node)
		ra(a, false);
	else if((*a)->next == bigger_node)
		rra(a, false);
	if((*a)->nbr > (*a)->next->nbr)
		sa(a, false);	
}

void	sort_five(t_stack **a, t_stack **b)
{
	while(stack_len(*a) > 3)
	{
		check_nodes(*a, *b);
		finish_rotation(a, find_small(*a), 'a');
		pb(b, a, false);
	}
}

void sort_all(t_stack **a, t_stack **b)
{
    int len;
    
    len = stack_len(*a);
	if(len-- > 3 && !is_sorted(*a))
		pb(b, a, false);
	if(len-- > 3 && !is_sorted(*a))
		pb(b, a, false);			
	if(len > 3 && !is_sorted(*a))
          move_b(a, b);
    sort_three(a);
    while(*b)
    {
        check_nodes(*a, *b);
        move_nodes(a, b);        
    } 
    set_position(*a);
}
