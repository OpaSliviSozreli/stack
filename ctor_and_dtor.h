#ifndef CTOR_AND_DTOR
#define CTOR_AND_DTOR

#include "struct.h"

int  stack_ctor( stack_t &stk, stack_element_t x );
void stack_assert_func( stack_t *stk, const char* file, int line );
int  stack_dtor( stack_t &stk );

#endif
