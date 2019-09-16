#ifndef STACK_H
#define STACK_H

typedef struct Stack {
	int top, capacity;
	int *arr;
}cstack_t;


cstack_t* create_stack(int cap);
void push(cstack_t* s, int val);
int pop(cstack_t* s);
int get_top(cstack_t* s);
int stack_empty(cstack_t* s);
void print_stack(cstack_t* s);

#endif