#include "stack.h"

void stack_init(Stack* s) {
    assert(s != NULL);
    s->top = -1;  
}

void push(Stack* s, char value) {
    assert(s != NULL);
    assert(!is_full(s));  
    
    s->top++;
    s->data[s->top] = value;
}

char pop(Stack* s) {
    assert(s != NULL);
    assert(!is_empty(s));  
    
    char value = s->data[s->top];
    s->top--;
    return value;
}

bool is_empty(const Stack* s) {
    assert(s != NULL);
    return (s->top == -1);
}

bool is_full(const Stack* s) {
    assert(s != NULL);
    return (s->top == (STACK_MAX_SIZE - 1));
}
