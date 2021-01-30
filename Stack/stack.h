#ifndef STACK_H
#define STACK_H

#define FULL_SIZE 1000

struct stack {
    int* items;
    int top;
};

typedef struct stack stack;

void create_empty_stack(stack*);
bool is_full(stack*);
bool is_empty(stack*);
void push(stack*, int);
int pop(stack*);
int last_item(stack* stk);
void print_stack(stack* stk);
int length(stack* stk);

#endif