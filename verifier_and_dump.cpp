#include <stdio.h>

#include "verifier_and_dump.h"
#include "ctor_and_dtor.h"
#include "struct.h"

int stack_error( stack_t* stk )
{
    if ( stk != 0 )
        stk->erroe_code = PTR_IS_ZERO;
    if ( stk->size < 0 )
        stk->erroe_code = STACK_WRONG_SIZE;
    if ( stk->compacity < 0 )
        stk->erroe_code = COMPACITY_IS_NEGATIVE;
    return 0;
}

int dump( stack_t* stk )
{
    STACK_ASSERT( stk );

    FILE* log_file = fopen( "log_file", "rb" );

    if ( !log_file )
        stk->erroe_code = CANT_OPEN_LOG_FILE;
    else
    {
        fprintf( log_file, " current error code %d\n", stk->erroe_code );
        
        fprintf( log_file, " the data is %0xp\n", stk->data );

        fprintf( log_file, "called from __func__ __LINE__ \n");
        fprintf( log_file, " named #stk born at __func__ __LINE__ \n");

        fprintf( log_file, "campacity is %d\n", stk->compacity );

        fprintf( log_file, "current size is %d\n", stk->size );

        for ( size_t i = 0; i < stk->compacity - 1; )
            fprintf( log_file, "data value is <%f>", stk->data[i] );
    }

    STACK_ASSERT( stk );
}