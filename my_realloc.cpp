#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_realloc.h"

void my_realloc( stack_t *stk )
{                                  
    STACK_ASSERT( stk );
    if ( stk->size == stk->capacity )
    {
        stk->data = ( stack_element_t* )realloc( ( char* )stk->data - sizeof( canary_t ), stk->capacity * 2 * sizeof( stack_element_t ) + 2 * sizeof( canary_t ) );
        set_poison( stk );
    }
    if ( stk->size <=  stk->capacity / 4 )
    { 
        stk->data = ( stack_element_t* )realloc( ( char* )stk->data - sizeof( canary_t ), stk->capacity / 2 * sizeof( stack_element_t ) + 2 * sizeof( canary_t ) );
        stk->capacity = stk->capacity / 4;
    }
    STACK_ASSERT( stk );
}

void set_poison( stack_t *stk )
{
    for ( int i = stk->size; i < stk->capacity; i++ ) 
        stk->data[i] = POISON; 
}