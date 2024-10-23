#include "stack.h"
#pragma CHECK_MISRA("-10.1")

void stack_init(Stack* s)
{
	assert(s != NULL);
	s->top = (int16_t)-1;
}

void push(Stack* s, int_least16_t push_value)
{
	assert(s != NULL);
	assert(!is_full(s));
	s->top = (int_least16_t)(s->top + 1);
	s->data[s->top] = push_value;
}

int_least16_t pop(Stack* s)
{
	assert(s != NULL);
	assert(!is_empty(s));

	int16_t pop_value = s->data[s->top];
	s->top = (int16_t)(s->top - 1);
	return pop_value;
}

int_least8_t is_empty(const Stack* s)
{
	assert(s != NULL);
	return (s->top == (int16_t)-1) ? (int_least8_t)1 : (int_least8_t)0;
}

int_least8_t is_full(const Stack* s)
{
	assert(s != NULL);
    return (s->top == (STACK_MAX_SIZE - (int16_t)1)) ? (int_least8_t)1 : (int_least8_t)0;
}
