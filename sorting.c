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
int partition(int [], int first, int last);
void quickSort(int [], int first, int last);

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
            // comparing the elements
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
            // checks if the current element if bigger than one of the following ones
            if(arr[j] < arr[min_pos]){
                // changing the min's position to the smallest element found
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

    // main loop, it marks the current element
    for(i = 1; i < n; i++){
        tmp = arr[i];   
        // second loop, it moves the elements bigger than the current one, jumping one position ahead 
        for(j = i; (j > 0) && (tmp < arr[j-1]); j--){ 
            arr[j] = arr[j-1];
        }
        // finaly the current is inserted on the right place
        arr[j] = tmp;
        
    }
}


// Here's the implementation of Merge Sort in C
void mergeSort(int arr[], int first, int last){
    // checks if there's only one element
    if(first == last){
        return;
    }

    // calculates the middle
    int middle = floor((first+last) / 2);

    // calling merge sort for the left part of the array
    mergeSort(arr, first, middle);
    // calling merge sort for the right part of the array
    mergeSort(arr, middle+1, last);
    // merging the results
    merge(arr, first, middle, last);
}


void merge(int arr[], int first, int middle, int last){
    int *tmp;
    int i;
    int left = first;
    int right = middle + 1;
    int tmp_len = last - first + 1;

    // creating the temporary array dynamically
    tmp = (int *) malloc(tmp_len * sizeof(int));

    if(tmp != NULL){
        // main loop, iterates over the temporary array
        for(i = 0; i < tmp_len; i++){
            // checking if both sub-arrays still have elements
            if((left <= middle) && (right <= last)){
                // comparing the current element at the left sub-array with the current one at right sub-array
                if(arr[left] < arr[right]){
                    // placing the left current element in the temporary array
                    tmp[i] = arr[left];
                    left++;
                }
                else{
                    // placing the right current element in the temporary array
                    tmp[i] = arr[right];
                    right++;
                }
            }
            // if there's no more elements in some of the sub-arrays, put the remaining ones into the temporary array
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
        // copying the temporary array into the main array
        for(int j = 0, i = first; j < tmp_len; j++, i++){
            arr[i] = tmp[j];
        }
    }

    // releasing the temporary array's dynamically allocated space
    free(tmp);
}


// Here's the implementation of Quick Sort in C
void quickSort(int arr[], int first, int last){
    // checking if there is more than one element in the array
    if(first < last){
        // calling the partition function and calculating the pivot element
        int pivot = partition(arr, first, last);
        // calling quickSort to the left part of the array
        quickSort(arr, first, pivot-1);
        // calling quickSort to the right part of the array
        quickSort(arr, pivot+1, last);
    }
}

int partition(int arr[], int first, int last){
    int left = first;
    int right = last;
    int tmp;
    int pivot = arr[first];

    // checking if left index still smaller than the right index
    while(left < right){
        // while the current left element is smaller than or equal to the pivot it increases the left index
        while(arr[left] <= pivot){
            left++;
        }
        // while the current right element is bigger than pivot it decreases the right index
        while(arr[right] > pivot){
            right--;
        }
        // checking if left index still smaller than the right index
        if(left < right){
            // swapping elements
            tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
        }
    }
    // in the end, the right index element goes to the pivot position and the pivot element goes to the right index
    arr[first] = arr[right];
    arr[right] = pivot;

    return right;
}


int main(){
    srand(time(0));
    int n;
    int method;

    printf("Type the array size: \n");
    scanf("%d", &n);

    int * arr;
    arr = (int *) malloc(n * sizeof(int));

    for(int j = 1; j <= 5; j++){
        printf("Array: \n");
        for(int i = 0; i < n; i++){
            arr[i] = (rand() % 20)-10;
            printf("%d ", arr[i]);
        }
        testMethod(arr, n, j);
    }
    printf("\n");
    
    return 0;
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
        printf("\nt = %lf s\n",((double) (CPU_time_end - CPU_time_start)) / CLOCKS_PER_SEC);
    }
    else if(method == 2){
        clock_t CPU_time_start = clock();
        selectionSort(arr, n);
        clock_t CPU_time_end = clock();

        printf("\nSelection Sorted Array:\n");
        for(i = 0; i < n; i++){
            printf("%d ", arr[i]);
        }
        printf("\nt = %lf s\n",((double) (CPU_time_end - CPU_time_start)) / CLOCKS_PER_SEC);
    }
    else if(method == 3){
        clock_t CPU_time_start = clock();
        insertionSort(arr, n);
        clock_t CPU_time_end = clock();

        printf("\nInsertion Sorted Array:\n");
        for(i = 0; i < n; i++){
            printf("%d ", arr[i]);
        }
        printf("\nt = %lf s\n",((double) (CPU_time_end - CPU_time_start)) / CLOCKS_PER_SEC);
    }
    else if(method == 4){
        clock_t CPU_time_start = clock();
        mergeSort(arr, 0, n-1);
        clock_t CPU_time_end = clock();

        printf("\nMerge Sorted Array:\n");
        for(i = 0; i < n; i++){
            printf("%d ", arr[i]);
        }
        printf("\nt = %lf s\n",((double) (CPU_time_end - CPU_time_start)) / CLOCKS_PER_SEC);
    }
    else if(method == 5){
        clock_t CPU_time_start = clock();
        quickSort(arr, 0, n-1);
        clock_t CPU_time_end = clock();

        printf("\nQuick Sorted Array:\n");
        for(i = 0; i < n; i++){
            printf("%d ", arr[i]);
        }
        printf("\nt = %lf s\n",((double) (CPU_time_end - CPU_time_start)) / CLOCKS_PER_SEC);
    }
    
    printf("\n");
}

