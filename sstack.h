#ifndef SIMPLE_STACK_H
#define SIMPLE_STACK_H

#include <stdlib.h> /* [cm]alloc */
#include <errno.h>

#define SIM_STK_EX_USAGE /* Simple StacK Example Usage */
/* comment it out to eliminate main from sstack.c */
/* The example requires 
   #define STACK_TYPE int
*/
#define STACK_TYPE int

struct stack {
    STACK_TYPE *items;
    unsigned size;
    STACK_TYPE *curr;
};

struct stack* new_stack(unsigned int size);
void free_stack(struct stack **stk);
STACK_TYPE pop(struct stack *stk);
STACK_TYPE push(struct stack *stk, STACK_TYPE val);


#endif
