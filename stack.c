#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


cstack_t* create_stack(int cap) {
	cstack_t* s = (cstack_t*) malloc(sizeof(cstack_t));
	s->top = -1;
	s->capacity = cap;
	s->arr = (int *) malloc(cap * sizeof(int));
	return s;
}

void push(cstack_t* s, int val) {
	if (s->top == s->capacity - 1) {
		printf("Stack overflow\n");
		return;
	}

	s->top++;
	s->arr[s->top] = val;
}

int pop(cstack_t* s) {
	if (s->top == -1) {
		printf("Stack underflow\n");
		return -1;
	}

	int tmp = s->arr[s->top];
	s->arr[s->top] = -1;
	s->top -= 1;
	return tmp;
}

int get_top(cstack_t* s) {
	if (s->top == -1) {
		printf("Stack underflow\n");
		return -1;
	}
	return s->arr[s->top];
}

void print_stack(cstack_t* s) {
	if (s->top == -1) {
		printf("Stack underflow\n");
		return;
	}

	for (int i = 0; i < s->capacity; i++)
		printf("%d ",s->arr[i] );
	printf("\n");

	printf("Top of stack is at %d\n",s->top );
}