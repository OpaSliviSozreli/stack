#include <string.h>
#include <stdlib.h>

#include "struct.h"
#include "my_realloc.h"

void* my_recalloc( stack_t *stk )
{
    if ( stk->size == stk->compacity )
        stk->data = ( stack_elemaemt_t* )realloc( stk->data, stk->size * 2 * sizeof( stack_elemaemt_t ) );
        memset( stk->data + size, size * sizeof( stack_elemaemt_t ) );
    if ( stk->size == 0.25 * stk->compacity )
        stk->data = ( stack_elemaemt_t* )realloc( stk->data, stk->size / 2 * sizeof( stack_elemaemt_t ) );
}