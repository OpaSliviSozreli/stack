#include <stdio.h>

#include "verifier_and_dump.h"

int stack_error( const stack_t* stk )
{
    if ( stk == NULL )
        return PTR_IS_ZERO;
    if ( stk->size < 0 )
        return STACK_WRONG_SIZE;
    if ( stk->capacity < 0 )
        return CAPACITY_IS_NEGATIVE;
    if ( stk->size > stk->capacity ) 
        return STACK_OVERFLOW;
    if ( stk->left_struct_canary != 0XEDA )
        return LEFT_CANARY_PROBLEM;
    if ( stk->right_struct_canary != 0XDEAD )
        return RIGHT_CANARY_PROBLEM;
    if ( stk->hash != MurmurHash2( ( char* )stk, 5 ) )
        return HASH_PROBLEM;

    return STACK_OK;
}

int dump( stack_t* stk ON_DEBUG( , const char* file, int line ) )
{
    ON_DEBUG(
        stk->file = file;
        stk->line = line;
            )
    STACK_ASSERT( stk );

    FILE* log_file = fopen( "Log_file.txt", "wb" ); 

    setvbuf( log_file, NULL, _IONBF, 0 );

    if ( !log_file )
        return CANT_OPEN_LOG_FILE;
 
    fprintf( stderr, "the data is %p\n", stk->data );

    fprintf( stderr, "called from %s %s \n", __func__, __FILE__ );
    fprintf( stderr, " named stack born at %s %s \n", __func__, __FILE__ );

    fprintf( stderr, "capacity is %d\n", stk->capacity );

    fprintf( stderr, "current size is %d\n", stk->size );

    fprintf( stderr, "error code is %d\n", stack_error( stk ) );

    fprintf( stderr, "hash is %d\n", stk->hash );

    for ( size_t i = 0; i < ( size_t )stk->capacity - 1; i++ )
        fprintf( stderr, "[%d] elem: data value is <%f>\n", i, stk->data[i] );

    fclose ( log_file );

    STACK_ASSERT( stk );

    return STACK_FUNC_OK; 
}

int stack_assert_func( stack_t* stk )
{
    int stk_error = stack_error( stk );

    if ( stk_error != STACK_OK )
        return stk_error;

    return STACK_OK;
}