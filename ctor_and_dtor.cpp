#include <assert.h>
#include <stdlib.h>
#include "ctor_and_dtor.h"

int stack_ctor( stack_t &stk, stack_element_t x )
{
    stack_t *ptr_to_stk = ( stack_t* )calloc( stk->compacity, sizeof( stack_element_t ) );

    stk->data = x;
    stk->size = 0;
    stk->compacity = 8;

    const char* file = "ctor_and_dtor";
    int line = 11;

    stack_assert_func( &stk, file, line );
}

void stack_assert_func( stack_t* stk, const char* file, int line )
{
    if ( !stack_ok( stk ) )
    {
        stack_dtor( stk );
        assert( 0 );
    }
}

int stack_dtor( stack_t* stk )
{
    free( &stk );
}