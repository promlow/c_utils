#include "sstack.h"

struct stack* new_stack(unsigned int size){
    struct stack *stk = malloc(sizeof(struct stack));
    if(!stk){
        errno = ENOMEM;
    }else{
        stk->size = size;
        stk->items = calloc(sizeof(STACK_TYPE), size);
        if(!stk->items){
            errno = ENOMEM;
            free_stack(&stk);
        }else{
            stk->curr = stk->items; /* point to top of stack */
        }
    }
    return stk;
}

void free_stack(struct stack **stk)
{
    if(*stk && stk){
        if((*stk)->items){
            free((*stk)->items);
        }
        free(*stk);
        *stk = NULL;
    }
}

STACK_TYPE pop(struct stack *stk){
    if(stk && stk->curr && 
       (stk->curr <= stk->items + stk->size)){
        return *--stk->curr;
    }else{
        errno = EINVAL;
        return (STACK_TYPE)-1;
    }
}

STACK_TYPE push(struct stack *stk, STACK_TYPE val){
    if(stk && stk->curr &&
       (stk->curr < stk->items + stk->size)){
        /* empty stack, point to offset 0 */
        if(stk->curr < stk->items){
            stk->curr = stk->items; 
        }
        *stk->curr++ = val;
        return *(stk->curr - 1);
    }else{
        errno = EINVAL;
        return val ^ -1;
    } 
}

