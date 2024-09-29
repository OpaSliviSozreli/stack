#include <assert.h>
#include <stdlib.h>

#include "ctor_and_dtor.h"
#include "my_recalloc.h"
#include "verifier_and_dump.h"

int stack_ctor( stack_t *stk, int compacity, const char* the_stack_name, const char* file, int line )
{
    my_recalloc( stk );

    stk->data[0] = compacity;
    stk->size = 0;
    stk->compacity = 8;

    STACK_ASSERT( stk );

    return 0;
}

void stack_assert_func( stack_t* stk, const char* file, int line )
{
    if ( stack_error( stk ) )
    {
        stack_dtor( stk );
        assert( 0 );
    }
}

int stack_dtor( stack_t* stk )
{
    STACK_ASSERT( stk );
    free( &stk );
    STACK_ASSERT( stk );
}