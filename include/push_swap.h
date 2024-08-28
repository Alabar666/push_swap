/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:15:43 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/08/28 21:09:12 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
**                              HEADERS
*/
# include "../libft/libft.h"
# include <stddef.h>
# include <stdlib.h> //malloc,free, exit + rand
# include <string.h> //strerror
# include <unistd.h> //read, write
/*
**                              CONSTANTS
*/
# define SA 1
# define SB 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RRA 7
# define RRB 8

typedef struct s_track
{
    int nbr;
    int idx;
    int pcost;    
    int cheap;

    struct s_stack  *next;
    struct s_stack  *prev; 
}   t_stack;


/*
**                              PROTOTYPES
*/


//erros
void    ft_error(void);
int error_syntax(char *str_nbr);


//list funcitions
t_stack	*ft_stack_new(void *content);

//utils
long	ft_atol(const char *str);


#endif