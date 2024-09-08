/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:31:27 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/09/08 18:36:56 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int ac, char **av)
{

    t_stack *a;
    t_stack *b; 

    a = NULL;
    b = NULL;
    if (ac < 2 || (ac == 2 && !av[1][0]))
        return (1);
    if(ac == 2)
    {
        av = ft_split(av[1], ' ');
        if(av == NULL)
            return 1;
        stack_init(&a, av);        
    }  
    else {
        stack_init(&a, av+1);
    }
    print_stacks(a, NULL);

    free_stack(&a);
    free_stack(&b);
    return (0);
}


