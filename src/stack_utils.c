

#include "../include/push_swap.h"

t_stack *find_last_node(t_stack *head)
{
    if (!head)
        return (NULL);
    while (head->next)
        head = head->next;
    return (head);
}

int stack_len(t_stack *stack)
{
    int len;
    t_stack *temp;

    temp = stack;
	len = 0;
    while (temp && temp->prev)
    {
        temp = temp->prev;
    }
    while (temp)
    {
        len++;
        temp = temp->next;
    }
    return len;
}