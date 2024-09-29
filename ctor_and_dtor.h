#ifndef CTOR_AND_DTOR
#define CTOR_AND_DTOR

#include "struct.h"

#define STACK_CTOR( stk, compacity ) stack_ctor( ( stk ), ( compacity ), #stk, __FILE__, __LINE__ )
#define STACK_ASSERT( stk ) stack_assert_func( ( stk ), __FILE__, __LINE__ )

int  stack_ctor( stack_t *stk, int compacity, const char* the_stack_name, const char* file, int line );
void stack_assert_func( stack_t *stk, const char* file, int line );
int  stack_dtor( stack_t* stk );

#endif
