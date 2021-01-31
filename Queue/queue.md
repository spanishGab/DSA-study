# Queue

The Queue is a type of computer science Data Structure. It can be used to control the order in which processes must execute in a computer system, handling interrupts on real-time systems, and other functionalities, like defining a priority for all its elements.

> Note: in my implementation, I chose to use integers as the queue values' type; The allocation type I chose was the Dynamic allocation; There are several queue types, like the Simple Queue, the Circular Queue, the Priority Queue and the Double Ended Queue (Deque). This article refers to the Circular Queue implementation.

## Queue working principle

The Queue works with the First In First Out (FIFO) principle, it means that the first element to enter it is the first element to leave it.

![Queue working](img/queue.png)

It is basicaly composed of four elements (attributes):

* an _items_ array, which keeps all the queue's elements.
* a _first_ indicator, which points to the queue's first element.
* a _last_ indicator, which points to the queue's last element.
* a _len_ indicator that keeps the quantity of elements in the queue.

> Note: in my implementation I chose to set _first_ = 0 and _last_ = -1.

The main Queue's operations (methods) are:

* enqueue
* dequeue
* is_full
* is_empty
* get_first
* get_last
* length

> Note: additionally to these functions, I've created the _create\_empty\_queue_ and _print\_queue_ functions. These functions' implementation (so as the whole Queue code) can be found at the ./Queue/queue.c file.

### Enqueue operation

The _enqueue_ operation includes a new element in the queue. Every new element is placed at the queue's end. Because this is a __Circular Queue__, the _last_ indicator must be updated in a different way (rather than just incrementing its value by one) before an enqueuing the element. The formula used to update _last's_ value is: `(_last_ + 1) % queue_full_size`, where:

* _last_ is the value of the _last_ indicator
* _queue\_full\_size_ is the max size of the queue (when it is filled)

After updating the _last_ index, the _items_ array recieves the new item at the position of _last_ index. To finish, the _len_ attribute is incremented by one.

Here is the implementation of the _enqueue_ function in the C language:

```
void enqueue(queue* q, int elm) {
    if(!is_full(q)) {
        q->last = (q->last+1) % FULL_SIZE;
        q->items[q->last] = elm;
        q->len++;
    }
}
```

### Dequeue operation

The _dequeue_ operation removes the first queue element returning its value. Every time an element is droped from the queue, the _first_ indicator is updated by the same principle used to update _last_ in the _enqueue_ function, the only change is that instead of _last_ we use the _first_ indicator value in the formula: `(_first_+1) % queue_full_size`. Then the _len_ value is decreased by one and the _items_ first element is returned.

Here is the implementation of the _dequeue_ function in the C language:

```
int dequeue(queue* q) {
    int out = q->items[q->first];
    q->first = (q->first+1) % FULL_SIZE;
    q->len--;
    return out;
}
```

### Is empty operation

To check if the queue is empty (on my implementation), we just need to check if the _len_ value is euqal to 0 (zero).

Here is the implementation of the _is\_empty_ function in the C language:

```
bool is_empty(queue* q) {
    return q->len == 0;
}
```

### Is full operation

To check if the queue is full (on my implementation), we just need to check if the _len_ value is equal to the FULL_SIZE (10 in this case) defined constant value.

Here is the implementation of the _is\_full_ function in the C language:

```
bool is_full(queue* q) {
    return q->len == FULL_SIZE;
}
```

### Length operation

The _length_ operation returns how many elements there are in the queue, (on my implementation) it just returns the value of _len_.

Here is the implementation of the _length_ function in the C language:

```
int length(queue* q) {
    return q->len;
}
```

### First item operation

The _get\_first_ operation just returns the element pointed by the _first_ indicator without removing it. 

Here is the implementation of the _get\_first_ function in the C language:

```
int get_first(queue* q) {
    return q->items[q->first];
}
```

### Last item operation

The _get\_last_ operation just returns the element pointed by the _last_ indicator without removing it. 

Here is the implementation of the _get\_last_ function in the C language:

```
int get_last(queue* q) {
    return q->items[q->last];
}
```

# References

[Programiz - DSA queues](https://www.programiz.com/dsa/queue)<br>
[Programiz - DSA cisrcular-queues](https://www.programiz.com/dsa/circular-queue)<br>
[Linguagem C Descomplicada](https://programacaodescomplicada.wordpress.com/indice/estrutura-de-dados/)</br>

> Note: The links referenced in this article were accessed on 2021-01-30 21:13:00 by the last time. All explanations and images used were prepared by the author himself, using as a basis the texts contained in the referred links.