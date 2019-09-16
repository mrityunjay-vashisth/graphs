#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>


typedef struct Queue {
	int front, rear, capacity;
	int *arr;
}queue_t;


queue_t* create_queue(int cap);
void enqueue(queue_t *q, int val);
int dequeu(queue_t *q);
int empty(queue_t *q);
void print_queue(queue_t* q);

#endif