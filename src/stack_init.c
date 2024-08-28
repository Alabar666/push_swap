/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:19:45 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/08/28 21:11:25 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <climits>

void stack_init(t_stack **a, char **av)
{
    long nbr;
    int i;

    i = -1;
    while(av[++i])
    {
        if(erro_syntax(av[i]))
            ft_error();
        nbr = ft_atol(av[i]);
        if(nbr > INT_MAX || nbr < INT_MIN)
            ft_error();
        ft_stack_new(a, (int)nbr);        
    }
        
}