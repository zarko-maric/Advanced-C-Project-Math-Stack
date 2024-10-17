#ifndef STACK_H
#define STACK_H

#pragma CHECK_MISRA("none")
#include <stddef.h>  
#include <stdbool.h>
#include <stdio.h> 
#include <stdint.h> 
#include <assert.h>  
#pragma CHECK_MISRA("all")

#define STACK_MAX_SIZE 100U


typedef struct {
    int8_t top;               
    char data[STACK_MAX_SIZE]; 
} Stack;


void stack_init(Stack* s);
void push(Stack* s, char value);
char pop(Stack* s);
bool is_empty(const Stack* s);
bool is_full(const Stack* s);

#endif 
