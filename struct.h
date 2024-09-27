#ifndef _STRUCT_H_
#define _STRUCT_H_

typedef double stack_element_t;

struct stack_t
{
    stack_element_t* data;
    int size;
    int compacity;
};

#endif