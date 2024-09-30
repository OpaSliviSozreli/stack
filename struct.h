#ifndef _STRUCT_H_
#define _STRUCT_H_

typedef double stack_element_t;

#ifdef DEFINE
    #define ON_DEBUG( code ) code
#else
    #define ON_DEBUG( code )
#endif

#define stack_name stk

const  stack_element_t _LEFT_CANARY_  = 0XEB01DA;
const  stack_element_t _RIGHT_CANARY_ = 0XE1DAC;

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
    STACK_OVERFLOW = 1,
    CANT_OPEN_LOG_FILE = 1
};

#endif