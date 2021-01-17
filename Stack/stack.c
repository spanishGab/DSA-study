#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

void create_empty_stack(stack* stk){
    stk->items = (int *) malloc(FULL_SIZE * sizeof(int));
    stk->top = 0;
}

bool is_full(stack* stk){
    return (stk->top == FULL_SIZE);
}

bool is_empty(stack* stk){
    return (stk->top == 0);
}

void push(stack* stk, int item){
    if (!is_full(stk)){
        stk->items[stk->top] = item;
        stk->top++;
    }
}

int pop(stack* stk){
    stk->top--;
    return stk->items[stk->top];
}

int last_item(stack* stk){
    return stk->items[stk->top-1];
}

void print_stack(stack* stk){
    if (is_empty(stk)){
        printf("\nThe Stack is empty!");
    }
    else{
        printf("Stack:");
        for(int i = 0; i < stk->top; i++){
            printf(" %d", stk->items[i]);
        }
    }
    printf("\n\n");
}

int length(stack* stk){
    return stk->top;
}