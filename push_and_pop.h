#ifndef _PUSH_AND_POP_
#define _PUSH_AND_POP_

#include "struct.h"
#include "my_realloc.h"
#include "verifier_and_dump.h"

int stack_push( stack_t* stk, stack_element_t value );
stack_element_t stack_pop( stack_t* stk );

#endif