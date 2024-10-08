#include <stdio.h>

#include "struct.h"
#include "ctor_and_dtor.h"
#include "push_and_pop.h"
#include "verifier_and_dump.h"

#define CHECK_( stk ) if ( stack_error( stk ) != STACK_OK ) stk_error =

int main()
{
    stack_t stk = {};
    
    int stk_error = 0;
    STACK_CTOR( &stk );
    CHECK_( &stk ) STACK_CTOR( &stk );
    
    stack_push( &stk, 100 );
    CHECK_( &stk ) stack_push( &stk, 100 );

    stack_push( &stk, 200 );
    CHECK_( &stk ) stack_push( &stk, 200 );

    stack_push( &stk, 300 );
    CHECK_( &stk ) stack_push( &stk, 300 );

    stack_push( &stk, 400 );
    CHECK_( &stk ) stack_push( &stk, 400 );

    stack_push( &stk, 500 );
    CHECK_( &stk ) stack_push( &stk, 500 );

    stack_element_t val = stack_pop( &stk );

    stack_dtor( &stk );

    STACK_DUMP( &stk );
}