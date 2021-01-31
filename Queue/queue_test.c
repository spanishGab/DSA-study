#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

int main(){
    printf("Begin\n");
    queue* q = (queue *) malloc(sizeof(queue));
    create_empty_queue(q);

    int op;
    int item;
    bool end = false;

    while (!end){
        printf("Which operation do you want to make?\n");
        printf("1 - enqueue\n");
        printf("2 - dequeue\n");
        printf("3 - see queue length\n");
        printf("4 - see queue items\n");
        printf("5 - see queue first item\n");
        printf("6 - see queue last item\n");
        printf("7 - end program\n");
        printf("-> ");
        scanf("%d", &op);
    
        switch (op){
            case 1:
                if (is_full(q)){
                    printf("\nThe Queue is full, can't put any more item on it!\n\n");
                }
                else{
                    printf("Type the new item: ");
                    scanf("%d", &item);
                    printf("\nEnqueuing %d to the queue\n\n", item);
                    enqueue(q, item);
                }
                break;
            case 2:
                if (is_empty(q)){
                    printf("\nThe Queue is empty, can't dequeue items anymore!\n\n");
                }
                else{
                    printf("\nDequeuing %d from the queue\n\n", dequeue(q));
                }
                break;
            case 3:
                printf("\nQueue length: %d\n\n", length(q));
                break;
            case 4:
                printf("\n");
                print_queue(q);
                printf("\n");
                break;
            case 5:
                if (is_empty(q)){
                    printf("\nThe Queue is empty!\n\n");
                }
                else{
                    printf("\nQueue first item: %d\n\n", get_first(q));
                }
                break;
            case 6:
                if (is_empty(q)){
                    printf("\nThe Queue is empty!\n\n");
                }
                else{
                    printf("\nQueue last item: %d\n\n", get_last(q));
                }
                break;
            case 7:
                end = true;
                break;
            default:
                printf("\nInvalid method, type again\n\n");
                break;       
        }
    }
    free(q);

    return 0;
}