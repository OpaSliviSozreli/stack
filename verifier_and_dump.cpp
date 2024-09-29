#include "verifier_and_dump.h"

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