#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 
   The bubble sort is a pair-comparing algorithm. It means that the ordination hapens
   as the algorithim iterates through the array comparing the adjacent elements. If the
   first element is grater than the second, they must swap their positions, else, the loop
   goes to the next comparison. This procedure is finished when there's no more elements to
   swap positions, this means that the array is sorted.

   The porocess hapens with two loops, the first one to control the iteration's last position and 
   the other one is to make the comparisons. In each iterration the biggest element of the array goes
   to the final position (if the sorting is in ascending order), as if it was "floating" like a bubble, 
   wich is why the algorithm's name is Bubble Sort
*/

// Here's the implementation of Bubble Sort in C
void bubbleSort(int arr[], int n){
    int lst_pos, j;
    int tmp;

    // loop to control the iteration's last position (where the second loop must stop)
    for(lst_pos = 0; lst_pos < n-1; lst_pos++){
        // loop to make the comparisons between the adjacent elements
        for(j = 0; j < n-lst_pos-1; j++){
            // the actual comparison (to make it in descending order change '>' to '<')
            if(arr[j] > arr[j+1]){
                // swaping positions
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }

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