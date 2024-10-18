#include "stack.h"
#include <assert.h>

void stack_init(Stack* s)
{
	assert(s != NULL);
	s->top = -1;
}

void push(Stack* s, int16_t value)
{
	assert(s != NULL);
	assert(!is_full(s));
	s->top++;
	s->data[s->top] = value;
}

int16_t pop(Stack* s)
{
	assert(s != NULL);
	assert(!is_empty(s));
	return s->data[s->top--];
}

bool is_empty(const Stack* s)
{
	assert(s != NULL);
	return s->top == -1;
}

bool is_full(const Stack* s)
{
	assert(s != NULL);
	return s->top == (STACK_MAX_SIZE - 1);
}
