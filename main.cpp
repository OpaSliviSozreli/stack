#include <stdio.h>

#include "struct.h"
#include "ctor_and_dtor.h"
#include "push_and_pop.h"


#define CHECK_ if ( !err ) err =

int main()
{
    stack_t stk = {};
    
    int err = 0;
    
    stack_ctor( &stk, 10 );
    CHECK_ stack_ctor( &stk, 10 );

    stack_push( &stk, 100 );
    CHECK_ &stackpush( &stk, 100 );

    stack_push( &stk, 200 );
    CHECK_ &stackpush( &stk, 200 );

    stack_push( &stk, 300 );
    CHECK_ &stackpush( &stk, 300 );

    stack_push( &stk, 400 );
    CHECK_ &stackpush( &stk, 400 );

    stack_push( &stk, 500 );
    CHECK_ &stackpush( &stk, 500 );

    stack_element_t x = 0;

    stack_push( &stk, &x );

    stack_element_t x = stack_pop( &stk )

    stack_dtor( &stk );
}