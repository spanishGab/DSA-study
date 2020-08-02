#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Here's the implementation of Bubble Sort in C
void bubbleSort(int arr[], int n){
    int lst_comp;
    int end = n;
    int i;
    int tmp;

    // loop that iterates until there's no more swap to make in the array
    do{
        lst_comp = 0;
        // loop to make the comparisons between the adjacent elements
        for(i = 0; i < end-1; i++){
            // the actual comparison (to make it in descending order change '>' to '<')
            if(arr[i] > arr[i+1]){
                // swaping positions
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                lst_comp = i;
            }
        }
        end--;
    }while(lst_comp != 0);

}


int main(){
    srand(time(0));
    time_t start_t, end_t;
    double time_taken;

    int n;
    printf("Type the array size: \n");
    scanf("%d", &n);

    int * arr;
    arr = (int *) malloc(n * sizeof(int));
    
    printf("Array: \n");
    for(int i = 0; i < n; i++){
        arr[i] = (rand() % 20)-10;
        printf("%d ", arr[i]);
    }

    printf("\nSorted Array:\n");
    clock_t CPU_time_start = clock();
    bubbleSort(arr, n);
    clock_t CPU_time_end = clock();
    
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    // printf("t = %lf\n",((double) (CPU_time_end - CPU_time_start)) / CLOCKS_PER_SEC);
    printf("\n");
    

    return 0;
}