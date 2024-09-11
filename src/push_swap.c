/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:56:16 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/09/11 20:29:56 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void push_swap(t_stack **a, t_stack **b)
{
    t_stack *small;
    int len;
    
    len = stack_len(*a);
    if(len == 5)
        sort_five(a, b);
    else
    {
        while(len-- > 3)
            pb(b, a, false);   
    }
    sort_three(a);
    while(*b)
    {
        check_nodes(*a, *b);
        
    } 
    set_position(*a);
    small = find_small(*a);
    if(small->above_median)
        while(*a != small)
            ra(a, false);
    else
        while(*a != small)
            rra(a, false);    
}
