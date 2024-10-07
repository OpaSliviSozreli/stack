#ifndef CTOR_AND_DTOR
#define CTOR_AND_DTOR

#include "struct.h"
#include "my_realloc.h"
#include "verifier_and_dump.h"
#include "hash.h"

#define STACK_CTOR( stk ) stack_ctor( ( stk ) ON_DEBUG(, __FILE__, __LINE__ ) )
                            
int stack_ctor( stack_t *stk ON_DEBUG(, const char* file, int line ) );
int stack_dtor( stack_t* stk );

#endif
