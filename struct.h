#ifndef _STRUCT_H_
#define _STRUCT_H_

typedef double stack_element_t;
typedef unsigned long long canary_t;

#ifdef DEBUG
    #define ON_DEBUG( ... ) __VA_ARGS__
#else
    #define ON_DEBUG( ... )
#endif

const  stack_element_t POISON = -666.13;

const  canary_t _LEFT_CANARY_  = 0XEB01DA;
const  canary_t _RIGHT_CANARY_ = 0XE1DAC;

struct stack_t
{
    canary_t left_struct_canary;
    ON_DEBUG( const char* stack_name )
    ON_DEBUG( const char* file_name )
    ON_DEBUG( int line )
    stack_element_t* data;
    size_t size;
    int capacity;
    unsigned int hash;
    canary_t right_struct_canary;
};

enum StackStatus // 
{
    STACK_FUNC_OK,
    STACK_FUNC_FAIL    
};

enum ErrorCode
{
    STACK_OK,        
    SIZE_IS_ZERO,         
    PTR_IS_ZERO,        
    STACK_WRONG_SIZE,     
    CAPACITY_IS_NEGATIVE, 
    STACK_OVERFLOW,    
    CANT_OPEN_LOG_FILE,
    HASH_PROBLEM
};

#endif