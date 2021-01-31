#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"queue.h"

void create_empty_queue(queue* q) {
    q->items = (int *) malloc(FULL_SIZE * sizeof(int));
    q->first = 0;
    q->last = -1;
    q->len = 0;
}

bool is_full(queue* q) {
    return q->len == FULL_SIZE;
}

bool is_empty(queue* q) {
    return q->len == 0;
}

void enqueue(queue* q, int elm) {
    if(!is_full(q)) {
        q->last = (q->last+1) % FULL_SIZE;
        q->items[q->last] = elm;
        q->len++;
    }
}

int dequeue(queue* q) {
    int out = q->items[q->first];
    q->first = (q->first+1) % FULL_SIZE;
    q->len--;
    return out;
}

int get_first(queue* q) {
    return q->items[q->first];
}

int get_last(queue* q) {
    return q->items[q->last];
}

int length(queue* q) {
    return q->len;
}

void print_queue(queue* q) {
    printf("Queue: ");
    int count = q->first;
    int i = 0;
    
    if (is_empty(q)){
        printf("\nThe Queue is empty!");
    }
    else {
        do {
            printf(" %d", q->items[count]);
            count = (count+1) % FULL_SIZE;
        
            if (i++ == length(q)){
                break;
            }
        } while (count != (q->last+1) % FULL_SIZE);
    }
    printf("\n");
}