# Sorting Algorithms

Sorting algorithms are a very interesting part of the __Data Structures and Algorithms__ theme. With them, we can understand some of the intricacies of computer science. In this article, I'm going to explain some of the most popular sorting algorithms.


## Bubble Sort

The Bubble Sort is an _exchanging_ algorithm. In Bubble Sort, the ordination happens as the __algorithm iterates over the array comparing the adjacent elements. If the current one is at the incorrect position, it must swap with the next one__, otherwise, the loop goes to the following comparison. This __process finishes when there are no more elements to exchange.__ It means that the array has been sorted.

The process works with two loops: the first one controls if there is still any swap to make; the other makes the comparisons between elements. In each iteration, __the biggest one goes to its right position__ as if it was "floating" like a bubble, which is why the algorithm's name is Bubble Sort.

This method is a simple way to think though it isn't efficient when dealing with a large amount of data.

> In terms of time performance:
>    * Better case: O(N)
>    * Average case: O(N²)
>    * Worst case: O(N²)

Down below is a possibility for the implementation of the Bubble Sort algorithm in the C language:

```
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
```

### Let's see an example of an ascending ordination with Bubble Sort:</br>
![BubbleSort](img/BubbleSort.png)


## Selection Sort

Selection Sort is a selection algorithm. In Selection Sort, the premise is: __the algorithm takes the first element of the array and compares it with all the others that follow when it finds the smallest one, it swaps them. If it doesn't find a smaller element it keeps the same starting array order.__ Then it goes to the next iteration and does the same thing with the second array's element. The process finishes when the penultimate reaches and is compared with the last one.

This process uses two loops: the first one iterates over the array's elements, marking the current element's position as the minimum element's position; the second one checks if this element is bigger than the following ones. When it finds a smaller one, it stores its position as the minimum's position and keeps doing this process until it reaches the last array's element. When it reaches the last one, it checks if the minimum's position is different from the starting stored position. If so, it swaps the element at the starting position with the one at the minimum's position.

This method is not efficient for a large amount of data, though, it is faster than the Bubble Sort.

> In terms of time performance:
>    * Better case: O(N²)
>    * Average case: O(N²)
>    * Worst case: O(N²)

Down below is the implementation of the Selection Sort algorithm in the C language:
```
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
```

### Let's see an example of an ascending ordination with Selection Sort:</br>
![SelectionSort](img/SelectionSort.png)

## Insertion Sort

The Insertion Sort method works with the _insertion_ of elements. A good __analogy__ used to understand Insertion Sort is a __card deck ordination.__ When sorting a cards' deck [i. e: K, J, Q...], we always assume that __the first card (K) is at the correct position__, then when we check the following one (J), __if it's smaller than the first one (K), we put it right before it, and then we have two cards sorted [J, K, Q...].__ If we find another unsorted card (Q) that is __smaller than the second card (K) and bigger than the first one (J), we put the second card (K) ahead of it (Q) and the third one (Q) right into the second's (K's) place, and so on [J, Q, K...].__ This process repeats until the end of the deck.

Insertion Sort algorithm works __separating the array into two parts__: the __first__ part is the __sorted sub-array__, the __second__ one is the __unsorted sub-array__. It walks through the array and __checks if the current element is smaller than the ones on its left-hand side (the sorted sub-array).__

In Insertion Sort, we have two loops: the first one marks the current element; the second one iterates over the sorted sub-array while it finds elements bigger than the current one. These elements walk one position ahead until the current one finds someone smaller than it, thus it goes to the place ahead of this element, and the next iteration comes in.

This algorithm is not efficient for a large amount of data, though, it is faster than the Selection Sort.

> In terms of time performance:
>    * Better case: O(N)
>    * Average case: O(N²)
>    * Worst case: O(N²)


Down below is the implementation of the Insertion Sort algorithm in the C language:
```
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
```

### Let's see an example of an ascending ordination with Insertion Sort:</br>
![Insertion Sort](img/InsertionSort.png)


## Merge Sort

Merge Sort algorithm uses the __[Divide and Conquer](https://www.programiz.com/dsa/divide-and-conquer) strategy__ to sort elements. It is based on __Recursion__ also. These two things united are the power of Merge Sort. Basically what the algorithm does is to __divide the array until all the elements get isolated__, this means that there is only one element left in each sub-array __(that's the base case of the recursion)__. When it has the elements divided at this level, it begins to _merge_ the sub-arrays created in the past levels.

The algorithm uses two functions: mergeSort() and merge():

### mergeSort():
This function divides the array into __two parts__: __left__ and __right__, to do this, it calculates the _middle_ of the array and calls itself again two times, the first one passing as arguments the array, and the _left part_ indicators, and the second one passing as arguments the array, and the _right part_ indicators. When the base case is reached, the function returns. In the end, it calls the merge() function, which sorts the array.

### merge(): 
This function is responsible for sorting the array passed as an argument. To do that, it uses the _first_, the _middle_, and the _last_ position indicators passed as arguments. It creates the _left_ and _right_ references and a __temporary array__ that will store the sorted values and then override the main array with its values.

It works with a loop that iterates over the temporary array. Inside the loop, the __first thing it does is to check if there's still have elements in both _left_ and _right_ sub-arrays__, if so, __it compares the current element at _left_ side with the one at the _right_ side and puts the smallest one in the temporary array. If some array (left or right) has no more elements to compare, then it gets the elements in the one which still has and puts them into the temporary array__ (because these remaining elements are already sorted). In the end, the function copies the temporary array into the main array.

This is a fast algorithm, especially when it treats large amounts of data. Its negative points are that it uses recursion and creates a temporary array during the sorting process.


> In terms of time performance:
>    * Better case: O(N log(N))
>    * Average case: O(N log(N))
>    * Worst case: O(N log(N))

Down below is the implementation of the Merge Sort algorithm in the C language:
```
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
```

### Let's see an example of an ascending ordination with Merge Sort:</br>
![MergeSort](img/MergeSort.png)


## Quick Sort

QuickSort uses the __[Divide and Conquer](https://www.programiz.com/dsa/divide-and-conquer) and the Recursion strategies__ to sort elements. The main idea in Quick Sort is that it picks up an element as the _pivot_, based on it, it __divides the array into two parts__. After that, the array is sorted by the _partition_ function where the elements at the __left side of the _pivot_ are smaller than it, and the ones at the right side of it are bigger than it.__ The __base case__ of the recursion in Quick Sort is when there's only one element left in the array passed as an argument.

There are two functions we need to build the QuickSort algorithm:

### quickSort()
This function is on to call the _partition_ function and then call itself passing the split main array as an argument: __the first call uses the elements before the _pivot_, and the second one uses the ones after the _pivot_ (never including the pivot).__

### partition()
Partition is the function that chooses the _pivot element_, this can be done in many ways, but the most common ones are to __take the array's first or last element (in my implementation I chose the first one).__ Based on the _pivot_, the _partition()_ function iterates over the sub-array (which is indicated by the _first_ and the _last_ positions) passed as an argument. 

There is the main loop, which checks if the _left_ index is smaller than the _right_ index. Inside the main loop, there are two more loops: the first one __checks if the elements at the _left_ side of the array are smaller than or equal to the _pivot_, while this condition is true the loop increases the _left_ index;__ the second loop __checks if the elements at the right side of the array are bigger than the _pivot_, while this condition is true the loop decreases the _right_ index.__ When these loops are over, there is an _if_ statement to check if the _left_ index is smaller than the _right_ index if this condition is true, __the elements at the _left_ and the _right_ positions are swapped because they are at the wrong side.__

At the end of the main loop, __the _pivot_ goes to the _right_ index's position (because the _right_ index indicates the last element smaller than the pivot) and the right index's element goes to the pivot (first element) position,__ then the _right_ index is returned as the pivot's index.

> Note: the _partition_ function doesn't sort the array, it just recombines the elements in such a way that the elements put at the left side of the _pivot_ are smaller than it, and the ones put at the right side of it are bigger than it. The array is sorted by the recursive call of the method, which calls itself until there's only one element left at each sub-part. At this point, the array is sorted.

Unlike Merge Sort, Quick Sort does not need to create a temporary array to store the sorted parts of the main array, it does that _in place_, which is why Quick Sort is considered better than Merge sort in terms of __Memory efficiency__.

> In terms of time performance:
>    * Better case: O(N log(N))
>    * Average case: O(N log(N))
>    * Worst case: O(N²)

Down below is the implementation of the Quick Sort algorithm in the C language:
```
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
```

### Let's see an example of an ascending ordination with QuickSort:</br>
![Quick Sort](img/QuickSort.png)

## References:

[LAMFO - Sorting Algorithms](https://lamfo-unb.github.io/2019/04/21/Sorting-algorithms/)</br>
[Programiz - DSA](https://www.programiz.com/dsa)</br>
[Linguagem C Descomplicada](https://programacaodescomplicada.wordpress.com/indice/estrutura-de-dados/)</br>
[FACE Prep](https://www.faceprep.in/c/sorting-algorithms/)

> Note: The links referenced in this article were accessed on 2021-01-10 22:05:00 by the last time. All explanations were prepared by the author himself, using as a basis the texts contained in the referred links.