#ifndef STACK_H
#define STACK_H

#pragma CHECK_MISRA("none")
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#pragma CHECK_MISRA("all")

#define STACK_MAX_SIZE 100U

typedef struct
{
	int16_t top;
	int16_t data[STACK_MAX_SIZE];
} Stack;

void stack_init(Stack* s);
void push(Stack* s, int16_t push_value);
int_least16_t pop(Stack* s);
int_least8_t is_empty(const Stack* s);
int_least8_t is_full(const Stack* s);

#endif /* STACK_H */
