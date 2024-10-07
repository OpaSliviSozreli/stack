#ifndef _MY_RECALLOC_H_
#define _MY_RECALLOC_H_

#include "struct.h"
#include "verifier_and_dump.h"

void my_realloc( stack_t *stk );
void  set_poison( stack_t *stk );

#endif