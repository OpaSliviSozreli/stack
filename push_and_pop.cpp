#include <stdlib.h>

#include "push_and_pop.h"

void stack_push( stack_t** stk, int size )
{
    stack_t* ptr_to_stk = ( stack_t* )calloc( stk->compacity, sizeof( stack_element_t ) );
    
    ptr_to_stk->size = size;
    ptr_to_stk->data = *stk;
    *stk = ptr_to_stk;
}

int stack_pop( stack_t** stk )
{
    stack_element_t temp = ( *stk )->size;

    stack_t* ptr_to_stk = *stk;
 
    *stk = ( *stk )->data;

    return temp;
}