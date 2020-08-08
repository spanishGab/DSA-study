# Sorting Algorithms

The sorting algorithms are a very interesting part of the Data Structures and Algorithms theme. With them, we can understand some of the intricacies of computer science. In this article, I'm going to explain some of the most popular sorting algorithms.


## Bubble Sort

The Bubble Sort is an _exchanging_ algorithm. In Bubble Sort, the ordination happens as the __algorithm iterates through the array comparing the adjacent elements, if the current is in the incorrect position, it must swap with the next one__, else, the loop goes to the following comparison. This __procedure finishes when there are no more elements to swap__ it means that the array has been sorted.

The process happens with __two loops__: the first one controls if there is still swap to make; the other one makes the comparisons between the elements. In each iteration, __the biggest one goes to its right position__ as if it was "floating" like a bubble, which is why the algorithm's name is Bubble Sort.

This method is a simple way to think when it comes to sorting, though, it's not efficient for a large amount of data.

> In terms of time performance:
>    * Better case: O(N)
>    * Average case: O(N²)
>    * Worst case: O(N²)

Down below is one possibility for the implementation of the Bubble Sort algorithm in C:

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
```

### Let's see an example of an ascending ordination:</br>
![BubbleSort](img/BubbleSort.png)


## Selection Sort

The Selection Sort is a _selection_ algorithm. In Selection Sort, __the premise is: the algorithm takes the first element of the array and compares it with all the other that follow when it finds the smallest element, it swaps them,  if it does not find a smaller one it keeps the same starting array order__. Then it goes to the next iteration and does the same thing with the second element. __The process finishes when the penultimate reaches and compared with the last one.__

The process uses __two loops__, the first one iterates over all the elements in the array, marking the current element's position as the position of the minimum element; the second one checks if this element is bigger than the following ones in the array. __When it finds a smaller one, it stores its position as the minimum's position and keeps doing this process until it reaches the last array's element. When it reaches the last one, it checks if the minimum's position is different from the starting position stored. If so, it swaps the element in the starting position with the one in the minimum's position.__

This method is not efficient for a large amount of data, though, it is faster than the Bubble Sort.

> In terms of time performance:
>    * Better case: O(N²)
>    * Average case: O(N²)
>    * Worst case: O(N²)

Down below is the implementation of the Selection Sort algorithm in C:
```
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
```

### Let's see an example of an ascending ordination:</br>
![SelectionSort](img/SelectionSort.png)

## Insertion Sort

The Insertion Sort method works with the _insertion_ of elements. A good and common __analogy__ used to understand Insertion Sort is a __card deck ordination__. When sorting a cards deck, we always assume that __the first card is already sorted__, then when we check the following one, __if it's smaller than the first one, we put it right before it, and then we have two cards sorted__. If we find another unsorted card that is __smaller than the second card and bigger than the first we pass the second card ahead and put the third one right into the second's place, and so on.__ This process repeats until the end of the deck.

Insertion Sort algorithm works __separating the array into two parts__: the __first__ part is the __sorted sub-array__, the __second__ one is the __unsorted sub-array__. It walks through the array and __checks if the current element is smaller than the ones on its left-hand side (the sorted sub-array).__

In Insertion Sort, we have __two loops__: the first one marks the current element; __the second one iterates over the sorted sub-array while it finds elements that are smaller than the current one.__ When this situation happens, __the elements that are bigger than the current one walk one position ahead until the current one finds someone smaller than it, thus it goes to the place ahead of this element, and the next iteration comes in.__

This algorithm is not efficient for a large amount of data, though, it is faster than the Selection Sort.

> In terms of time performance:
>    * Better case: O(N)
>    * Average case: O(N²)
>    * Worst case: O(N²)


Down below is the implementation of the Insertion Sort algorithm in C
```
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
```

### Let's see an example of an ascending ordination:</br>
![Insertion Sort](img/InsertionSort.png)


# Merge Sort

Merge Sort algorithm uses the [Divide and Conquer](https://www.programiz.com/dsa/divide-and-conquer) strategy to sort elements. It is based on recursion also. These two things united are the power of Merge Sort. Basically what the algorithm does is to divide the array until all the elements get isolated, this means that there is only one element left in the sub-array (that's the base case of the recursion). When it has the elements divided at this level, it begins to _merge_ the sub-arrays created in the past levels.

The algorithm uses two functions: mergeSort() and merge():

### mergeSort():
This function is responsible to divide the array into two parts: left and right, to do this, it calculates the _middle_ of the array and calls itself again two times, the first one passing as arguments the array, and the _left part_ indicators, and the second one passing as arguments the array, and the _right part_ indicators. When the base case is reached, the function returns. In the end, it calls the merge() function, which sorts the array.

### merge(): 
This function is responsible for sorting the array passed as an argument. To do that, it uses the _first_, the _middle_, and the _last_ position indicators passed as arguments. It creates the _left_ and _right_ references and a temporary array that will store the sorted values and then will override the main array with its values.

It works with a loop that iterates over the temporary array. Inside the loop, the first thing it does is to check if there still have any element in both _left_ and _right_ sub-arrays, if so, it compares the current element in the _left_ side with the one in the _right_ side and puts the smallest one in the temporary array. If one of the arrays has no more elements to compare, then it gets the elements in the one which still has and puts them into the temporary array, because these remaining elements are already sorted. In the end, the function copies the temporary array into the main array.

This is a fast algorithm, especially when it treats large amounts of data. Its negative points are that it uses recursion and creates a temporary array during the sort process.

> In terms of performance:
>    * Better case: O(N log(N))
>    * Average case: O(N log(N))
>    * Worst case: O(N log(N))

Down below is the implementation of the Merge Sort algorithm in C
```
void mergeSort(int arr[], int first, int last){
    if(first == last){
        return;
    }

    int middle = floor((first+last) / 2);

    mergeSort(arr, first, middle);
    mergeSort(arr, middle+1, last);
    merge(arr, first, middle, last);
}


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

```

### Let's see an example of an ascending ordination:</br>
![MergeSort](img/MergeSort.png)


## References:

[LAMFO - Sorting Algorithms](https://lamfo-unb.github.io/2019/04/21/Sorting-algorithms/)</br>
[Programiz - DSA](https://www.programiz.com/dsa)</br>
[Linguagem C Descomplicada](https://programacaodescomplicada.wordpress.com/indice/estrutura-de-dados/)</br>
[FACE Prep](https://www.faceprep.in/c/sorting-algorithms/)
