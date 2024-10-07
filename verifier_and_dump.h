#ifndef _VERIFIER_AND_DUMP_
#define _VERIFIER_AND_DUMP_

#include "struct.h"
#include "hash.h"

#define STACK_DUMP( stk )  dump( ( stk ) ON_DEBUG( , __FILE__, __LINE__ ) )
#define STACK_ASSERT( stk )  if ( stack_assert_func( ( stk ) ) != STACK_OK )\
                                 STACK_DUMP ( stk );


int dump( stack_t* stk ON_DEBUG( , const char* file, int line ) );
int stack_assert_func( stack_t *stk );
int stack_error( const stack_t* stk );

#endif