#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void testMethod(int [], int n, int method);
void bubbleSort(int [], int n);
void selectionSort(int [], int n);

int main(){
    srand(time(0));
    int n;
    int method;

    printf("Type the array size: \n");
    scanf("%d", &n);

    printf("\nType the method you want to test: \n");
    printf("1 -> Bubble Sort\n");
    printf("2 -> Selection Sort\n");
    scanf("%d", &method);

    int * arr;
    arr = (int *) malloc(n * sizeof(int));

    printf("Array: \n");
    for(int i = 0; i < n; i++){
        arr[i] = (rand() % 20)-10;
        printf("%d ", arr[i]);
    }

    switch (method){
        case 1:
            testMethod(arr, n, 1);
            break;
        case 2:
            testMethod(arr, n, 2);
            break;

    }
    

    return 0;
}
// Here's the implementation of Bubble Sort in C
void bubbleSort(int arr[], int n){
    int last_comp;
    int end = n;
    int i;
    int tmp;

    // loop that iterates until there's no more swap to make in the array
    do{
        last_comp = 0;
        // loop to make the comparisons between the adjacent elements
        for(i = 0; i < end-1; i++){
            // the actual comparison (to make it in descending order change '>' to '<')
            if(arr[i] > arr[i+1]){
                // swaping positions
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                last_comp = i;
            }
        }
        end--;
    }while(last_comp != 0);

}

void selectionSort(int arr[], int n){
    int i;
    int j;
    int min_pos;
    int tmp;

    // loop to mark the current element position
    for(i = 0; i < n-1; i++){
        // assuming that the current element is the minimum element of the sequence
        min_pos = i;
        // loop to make the comparisons between the current element and the other elements
        for(j = i+1; j < n; j++){ 
            // checks if the current element if smaller than the following ones
            if(arr[j] < arr[min_pos]){
                min_pos = j;
            }
        }
        // checks if the minimum element position if diffrent from the current element position
        if(min_pos != i){
            // swaping positions
            tmp = arr[i];
            arr[i] = arr[min_pos];
            arr[min_pos] = tmp;
        }
    }
}


void testMethod(int arr[], int n, int method){
    time_t start_t, end_t;
    double time_taken;
    clock_t CPU_time_start, CPU_time_end;


    if(method == 1){
        clock_t CPU_time_start = clock();
        bubbleSort(arr, n);
        clock_t CPU_time_end = clock();
        
        printf("\nBubble Sorted Array:\n");
        for(int i = 0; i < n; i++){
            printf("%d ", arr[i]);
        }
        // printf("\nt = %lf s\n",((double) (CPU_time_end - CPU_time_start)) / CLOCKS_PER_SEC);
    }
    else if(method == 2){
        clock_t CPU_time_start = clock();
        selectionSort(arr, n);
        clock_t CPU_time_end = clock();

        printf("\nSelection Sorted Array:\n");
        for(int i = 0; i < n; i++){
            printf("%d ", arr[i]);
        }
        // printf("\nt = %lf s\n",((double) (CPU_time_end - CPU_time_start)) / CLOCKS_PER_SEC);
    }
    
    
    
    printf("\n");
}

