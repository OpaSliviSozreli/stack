#include <stdlib.h>

#include "push_and_pop.h" 
#include "my_recalloc.h"
#include "ctor_and_dtor.h"

int stack_push( stack_t* stk, stack_element_t value )
{
    STACK_ASSERT( stk );
    my_recalloc( stk );
    
    stk->data[stk->size] = value;
    stk->data[stk->size - 1] = _RIGHT_CANARY_;
    stk->size++;

    if ( stk->size == 0 )
        stk->erroe_code = STACK_OVERFLOW;

    STACK_ASSERT( stk );
    return 0;
}

int stack_pop( stack_t* stk )
{
    STACK_ASSERT( stk );
    my_recalloc( stk );

    stack_element_t value = stk->data[stk->size - 2];
    stk->size--;
    
    STACK_ASSERT( stk );

    return value;
}