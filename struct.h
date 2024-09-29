#ifndef _STRUCT_H_
#define _STRUCT_H_

typedef double stack_element_t;

#ifdef DEFINE
    #define ON_DEBUG( code ) code
#else
    #define ON_DEBUG( code )
#endif

#define stack_name stk
struct stack_t
{
    ON_DEBUG( const char* file_name )
    ON_DEBUG( const char* stack_name )
    ErrorCode erroe_code;
    stack_element_t* data;
    size_t size;
    int compacity;
};

enum ErrorCode
{
    PTR_IS_ZERO = 1,
    STACK_WRONG_SIZE = 1,
    COMPACITY_IS_NEGATIVE = 1,
    STACK_OVERFLOW = 1
};

#endif