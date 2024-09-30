#include <string.h>
#include <stdlib.h>

#include "my_recalloc.h"
#include "ctor_and_dtor.h"

void* my_recalloc( stack_t *stk )
{   
    STACK_ASSERT( stk );
    if ( stk->size == stk->compacity )
        stk->data = ( stack_element_t* )realloc( stk->data, ( stk->size * 2 + 2 ) * sizeof( stack_element_t ) );
        memset( ( stk->data + stk->size + 2 ), 0, ( stk->size - 2 ) * sizeof( stack_element_t ) );
    if ( stk->size == 0.25 * stk->compacity )
        stk->data = ( stack_element_t* )realloc( stk->data, stk->size / 2 * sizeof( stack_element_t ) );
    STACK_ASSERT( stk );
}