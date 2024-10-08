/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:15:43 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/09/15 16:22:24 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
**                              HEADERS
*/
# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h> // for bool
# include <stddef.h>
# include <stdlib.h> //malloc,free, exit + rand
# include <string.h> //strerror
# include <unistd.h> //read, write

# define RESET "\033[0m"
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
/*
**                              STRUCTS
*/

typedef struct s_stack
{
	int				nbr;
	int				idx;
	int				pcost;
	bool			cheap;
	bool			above_median;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

/*
**                              PROTOTYPES
*/

// erros
int					error_syntax(char *str_nbr);
int					error_nbr_repet(t_stack *a, int nbr);
void				ft_error(t_stack **a, t_stack **b, char **av, bool split);
bool				is_empty_split(char **split_av);

// free
void				free_stack(t_stack **stack);
void				free_av(char **av);

// stack
void				stack_init(t_stack **a, char **av, bool split);
int					stack_len(t_stack *stack);
void				set_position(t_stack *stack);
t_stack				*return_cheap(t_stack *stack);
t_stack				*find_small(t_stack *stack);
t_stack				*find_last_node(t_stack *head);

// main
int					init_stacks(int ac, char **av, t_stack **a,
						char ***split_av);
int					push_swap_sort(int ac, char **split_av, t_stack *a);

// commands
// push
void				push(t_stack **dest, t_stack **src);
void				pa(t_stack **a, t_stack **b, bool flag);
void				pb(t_stack **b, t_stack **a, bool flag);
// swap
void				swap(t_stack **head);
void				sa(t_stack **a, bool flag);
void				sb(t_stack **b, bool flag);
void				ss(t_stack **a, t_stack **b, bool flag);
// rotate
void				rotate(t_stack **stack);
void				ra(t_stack **a, bool flag);
void				rb(t_stack **b, bool flag);
void				rr(t_stack **a, t_stack **b, bool flag);
// reverse rotate
void				reverse_rotate(t_stack **stack);
void				rra(t_stack **a, bool flag);
void				rrb(t_stack **b, bool flag);
void				rrr(t_stack **a, t_stack **b, bool flag);

// sort
bool				is_sorted(t_stack *stack);
t_stack				*find_bigger(t_stack *stack);
void				sort_three(t_stack **a);
void				sort_five(t_stack **a, t_stack **b);
void				push_swap(t_stack **a, t_stack **b);
void				finish_rotation(t_stack **stack, t_stack *top_node,
						char flag);
void				move_nodes(t_stack **a, t_stack **b);
void				reverse_rotate_both(t_stack **a, t_stack **b,
						t_stack *cheap);
void				rotate_both(t_stack **a, t_stack **b, t_stack *cheap);
void				sort_all(t_stack **a, t_stack **b);

// checks
void				check_nodes(t_stack *a, t_stack *b);
void				set_small(t_stack *b);
void				set_cost(t_stack *a, t_stack *b);
void				set_target(t_stack *a, t_stack *b);
void				set_position(t_stack *stack);
int					check_above(t_stack *stack, int target);
void				check_before_push(t_stack **a, t_stack **b, int target);
t_stack				*find_above(t_stack *stack, int target);
void				move_b(t_stack **a, t_stack **b);

// list funcitions
t_stack				*stack_new(int content);
t_stack				*ft_stack_new(void *content);
t_stack				*stack_new_node(t_stack *node, int content);

// utils
long				ft_atol(const char *str);
void				print_stacks(t_stack *stack1, t_stack *stack2);
long				nbr_max(t_stack *a);
long				nbr_min(t_stack *a);

// bonus
void				fd_command(t_stack **a, t_stack **b, char *command);
void				validate(t_stack *a, t_stack *b);
int					init_stacks_bonus(int ac, char **av, t_stack **a,
						char ***split_av);
void				process_commands(t_stack **a, t_stack **b);

#endif