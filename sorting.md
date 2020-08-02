# Sorting Algorithms

The sorting algorithms are a very intresting part of the Data Structures and Algorithms theme. With them we can understand some of the intricacies of the computer science. In this article I'm going to explain some of the most popular sorting algorithms.


## Bubble Sort

The Bubble Sort is an _exchanging_ algorithm. In Bubble Sort the ordination hapens as the __algorithim iterates through the array comparing the adjacent elements, if the current element is in the incorrect position, it must swap with the next one__, else, the loop goes to the next comparison. This __procedure is finished when there's no more elements to swap__, it means that the array is sorted.

The process happens with __two loops__: the first one controls if there is still swap to make; the other one makes the comparisons between the elements. In each iterration __the biggest (or smallest, it depends if the order is ascending or descending) element of the array goes to it's right position__, as if it was "floating" like a bubble, wich is why the algorithm's name is Bubble Sort.

This method is a very simple way to think when it comes to sorting, though, it's not efficient for a big amount of data

> In terms of performance:
>    * Better case: O(N)
>    * Average case: O(N²)
>    * Worst case: O(N²)

Down below is one possibility for the implementation of the Bubble Sort in C

```
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
```


## References:

[LAMFO - Sorting Algorithms](https://lamfo-unb.github.io/2019/04/21/Sorting-algorithms/)</br>
[Programiz - DSA](https://www.programiz.com/dsa)</br>
[Linguagem C Descomplicada](https://programacaodescomplicada.wordpress.com/indice/estrutura-de-dados/)</br>
[FACE Prep](https://www.faceprep.in/c/sorting-algorithms/)