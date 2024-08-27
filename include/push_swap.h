/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:15:43 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/08/27 22:05:13 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
/*
**                              HEADERS
*/
# include "./libft/libft.h"
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
    bool cheap;

    struct s_stack  *next;
    struct s_stack  *prev; 
}   t_stack;


/*
**                              PROTOTYPES
*/


//
void    ft_error(void);