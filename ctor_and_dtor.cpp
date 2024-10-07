#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "ctor_and_dtor.h"

int stack_ctor( stack_t *stk ON_DEBUG(, const char* file, int line ) )
{
    ON_DEBUG(
            stk->file = file;
            stk->line = line;
            )

    stk->size = 0;
    stk->capacity = 8;
    stk->data = ( stack_element_t* )calloc( stk->capacity, sizeof( stack_element_t ) );

    stk->hash = MurmurHash2( ( char* )stk, 5 );

    *( canary_t* )( ( char* )stk->data - sizeof( _LEFT_CANARY_ ) ) = _LEFT_CANARY_;

    *( canary_t* )( ( char* )stk->data + stk->capacity * sizeof( stack_element_t ) + sizeof( _RIGHT_CANARY_ ) ) = _RIGHT_CANARY_; 

    stk->left_struct_canary  = 0XEDA;
    stk->right_struct_canary = 0XDEAD;

    set_poison( stk );

    STACK_ASSERT( stk );

    return STACK_FUNC_OK;
}

int stack_dtor( stack_t* stk )
{
    STACK_ASSERT( stk );

    for ( size_t i = 0; i < ( size_t )stk->capacity - 1; i++ )
        stk->data = 0;
        
    stk->capacity = 0;
    stk->size = 0;

    free( stk->data ); 

    STACK_ASSERT( stk );

    return STACK_FUNC_OK;
}