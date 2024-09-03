/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:31:27 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/09/03 21:10:53 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int ac, char **av)
{

    t_stack *a;
    t_stack *b; 

    a = NULL;
    b = NULL;
    if(ac < 2)
        return 0;
    if (ac == 2 && av[1][0])
    {
        av = ft_split(av[1], ' ');
        stack_init(&a, av + 1);

        
    }  



    return (0);
}


