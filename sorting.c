#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

void testMethod(int [], int n, int method);
void bubbleSort(int [], int n);
void selectionSort(int [], int n);
void insertionSort(int [], int n);
void merge(int [], int first, int middle, int last);
void mergeSort(int [], int first, int last);

int main(){
    srand(time(0));
    int n;
    int method;

    printf("Type the array size: \n");
    scanf("%d", &n);

    printf("\nType the method you want to test: \n");
    printf("1 -> Bubble Sort\n");
    printf("2 -> Selection Sort\n");
    printf("3 -> Insertion Sort\n");
    printf("4 -> Merge Sort\n");
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
        case 3:
            testMethod(arr, n, 3);
            break;
        case 4:
            testMethod(arr, n, 4);
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

// Here's the implementation of Selection Sort in C
void selectionSort(int arr[], int n){
    int i;
    int j;
    int min_pos;
    int tmp;

    // loop that marks the current element position
    for(i = 0; i < n-1; i++){
        // assuming that the current element is the minimum element of the sequence
        min_pos = i;
        // loop that makes the comparisons between the current and the other elements
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

// Here's the implementation of Insertion Sort in C
void insertionSort(int arr[], int n){
    int i;
    int j;
    int tmp;

    for(i = 1; i < n; i++){
        tmp = arr[i];   
        for(j = i; (j > 0) && (tmp < arr[j-1]); j--){    
            arr[j] = arr[j-1];
        }
        arr[j] = tmp;
        
    }
}


void mergeSort(int arr[], int first, int last){
    if(first == last){
        return;
    }

    int middle = floor((first+last) / 2);

    mergeSort(arr, first, middle);
    mergeSort(arr, middle+1, last);
    merge(arr, first, middle, last);
}


// Here's the implementation of Merge Sort in C
void merge(int arr[], int first, int middle, int last){
    int *tmp;
    int i;
    int left = first;
    int right = middle + 1;
    int tmp_len = last - first + 1;
    tmp = (int *) malloc(tmp_len * sizeof(int));

    if(tmp != NULL){
        for(i = 0; i < tmp_len; i++){
            if((left <= middle) && (right <= last)){
                if(arr[left] < arr[right]){
                    tmp[i] = arr[left];
                    left++;
                }
                else{
                    tmp[i] = arr[right];
                    right++;
                }
            }
            else{
                if(left > middle){
                    tmp[i] = arr[right];
                    right++;
                }
                else{
                    tmp[i] = arr[left];
                    left++;
                }
            }
        }
        for(int j = 0, i = first; j < tmp_len; j++, i++){
            arr[i] = tmp[j];
        }
    }

    free(tmp);
}


void testMethod(int arr[], int n, int method){
    time_t start_t, end_t;
    double time_taken;
    clock_t CPU_time_start, CPU_time_end;
    int i;


    if(method == 1){
        clock_t CPU_time_start = clock();
        bubbleSort(arr, n);
        clock_t CPU_time_end = clock();
        
        printf("\nBubble Sorted Array:\n");
        for(i = 0; i < n; i++){
            printf("%d ", arr[i]);
        }
        // printf("\nt = %lf s\n",((double) (CPU_time_end - CPU_time_start)) / CLOCKS_PER_SEC);
    }
    else if(method == 2){
        clock_t CPU_time_start = clock();
        selectionSort(arr, n);
        clock_t CPU_time_end = clock();

        printf("\nSelection Sorted Array:\n");
        for(i = 0; i < n; i++){
            printf("%d ", arr[i]);
        }
        // printf("\nt = %lf s\n",((double) (CPU_time_end - CPU_time_start)) / CLOCKS_PER_SEC);
    }
    else if(method == 3){
        clock_t CPU_time_start = clock();
        insertionSort(arr, n);
        clock_t CPU_time_end = clock();

        printf("\nInsertion Sorted Array:\n");
        for(i = 0; i < n; i++){
            printf("%d ", arr[i]);
        }
        // printf("\nt = %lf s\n",((double) (CPU_time_end - CPU_time_start)) / CLOCKS_PER_SEC);
    }
    else if(method == 4){
        clock_t CPU_time_start = clock();
        mergeSort(arr, 0, n-1);
        clock_t CPU_time_end = clock();

        printf("\nMergeSorted Array:\n");
        for(i = 0; i < n; i++){
            printf("%d ", arr[i]);
        }
        // printf("\nt = %lf s\n",((double) (CPU_time_end - CPU_time_start)) / CLOCKS_PER_SEC);
    }
    
    
    printf("\n");
}

