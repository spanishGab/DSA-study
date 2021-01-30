#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

int main(){
    printf("Begin\n");
    stack* stk = (stack *) malloc(sizeof(stack));
    create_empty_stack(stk);

    int op;
    int item;
    bool end = false;

    while (!end){
        printf("Which operation do you want to make?\n");
        printf("1 - push\n");
        printf("2 - pop\n");
        printf("3 - see stack length\n");
        printf("4 - see stack items\n");
        printf("5 - see stack last item\n");
        printf("6 - end program\n");
        printf("-> ");
        scanf("%d", &op);
    
        switch (op){
            case 1:
                if (is_full(stk)){
                    printf("\nThe Stack is full, can't put any more item on it!\n\n");
                }
                else{
                    printf("Type the new item: ");
                    scanf("%d", &item);
                    printf("\nPushing %d to the stack\n\n", item);
                    push(stk, item);
                }
                break;
            case 2:
                if (is_empty(stk)){
                    printf("\nThe Stack is empty, can't drop items anymore!\n\n");
                }
                else{
                    printf("\nPoping %d from the stack\n\n", pop(stk));
                }
                break;
            case 3:
                printf("\nStack length: %d\n\n", length(stk));
                break;
            case 4:
                print_stack(stk);
                break;
            case 5:
                if (is_empty(stk)){
                    printf("\nThe Stack is empty!\n\n");
                }
                else{
                    printf("\nStack last item: %d\n\n", last_item(stk));
                }
                break;
            case 6:
                end = true;
                break;
            default:
                printf("\nInvalid method, type again\n\n");
                break;       
        }
    }

    return 0;
}