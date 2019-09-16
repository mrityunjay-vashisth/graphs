#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


queue_t* create_queue(int cap) {
	queue_t *q = (queue_t*) malloc(sizeof(queue_t));
	q->front = -1;
	q->rear = -1;
	q->capacity = cap;
	q->arr = (int *) malloc(cap*sizeof(int));
	return q;
}


void enqueue(queue_t *q, int val) {
	if ((q->rear + 1) % q->capacity == q->front) {
		printf("Overflow\n");
		return;
	}

	q->rear++;
	q->rear %= q->capacity;
	q->arr[q->rear] = val;

	if (q->front == -1)
		q->front++;

}


int dequeu(queue_t *q) {
	if (q->front == -1) {
		printf("Underflow\n");
		return -1;
	}
	
	int tmp = q->arr[q->front];
	q->arr[q->front] = -1;
	if (q->front == q->rear) {
		q->front = -1;
		q->rear = -1;
	}
	else {
		q->front++;
		q->front %= q->capacity;
	}
	return tmp;
}


void print_queue(queue_t* q) {
	int i;
	for (i = 0; i < q->capacity; i++) {
		printf("%d ", q->arr[i]);
	}
	printf("\n");
	printf("Front is at : %d\n", q->front);
	printf("Rear is at : %d\n", q->rear);
}