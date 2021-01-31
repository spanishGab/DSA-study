#ifndef QUEUE_H
#define QUEUE_H

#define FULL_SIZE 10

struct queue {
    int* items;
    int first;
    int last;
    int len;
};
typedef struct queue queue;

void create_empty_queue(queue* q);
bool is_full(queue* q);
bool is_empty(queue* q);
void enqueue(queue* q, int elm);
int dequeue(queue* q);
int get_first(queue* q);
int get_last(queue* q);
int length(queue* q);
void print_queue(queue* q) ;

#endif