#include <stdlib.h>
#include <stdio.h>

#include "push_and_pop.h" 

int stack_push( stack_t* stk, stack_element_t value )
{
    STACK_ASSERT( stk );
    my_realloc( stk );

    stk->data[stk->size] = value;
    stk->size++;

    if ( stk->size > stk->capacity ) 
        return STACK_OVERFLOW;

    STACK_ASSERT( stk );

    return STACK_FUNC_OK;
}

stack_element_t stack_pop( stack_t* stk ) 
{
    STACK_ASSERT( stk );
    
    my_realloc( stk );

    if ( stk->size == 0 )
    {
        fprintf( stderr, "stack size is zero" );
        return SIZE_IS_ZERO;
    }

    stack_element_t value = stk->data[stk->size];
    stk->size--;
    
    STACK_ASSERT( stk );

    return value;
}