# Stack

The Stack is an important Data Structure for Computer Science. It can be used to reverse a string, save brwowser navigation URLs to to allow users to return to the previous visited site and to control the code execution flow by the OS (Call/Execution Stack), beyond other functionalities.

## Stack working principle

The Stack works with the Last In First Out (LIFO) principle, it means that the last element to enter it is the first element to leave it.

![Stack working](img/stack.png)

It is composed of basically two elements (attributes): 
* a _top_ indicator, that keeps track of the stack's top element. It can be initialized with 0 or -1 value, it depends on the implementation.
* an _items_ array, which keeps all the steck's elements.

> Note: in my implementation I chose to set _top_ = 0.

The main Stack operations (methods) are:
* push
* pop
* is empty
* is full
* length 
* last item

> Note: additionaly to those, I've created the _create\_empty\_stack_ and _print\_stack_ operations. These functions' implementation (so as the whole the Stack implementation code) can be found at the ./Stack/stack.c file.
  
### Push operation

The _push_ operation includes a new element in the stack. Every new element is placed at the stack's end (its top). When this element enters the _items_ array recieves it at the _top's_ index and then the _top_ indicator is incremented by one.

Here is the implementation of the _push_ function in the C language:

```
void push(stack* stk, int item){
    if (!is_full(stk)){
        stk->items[stk->top] = item;
        stk->top++;
    }
}
```

> Note: because C has no exceptions to throw, it is necessary to control the insertion of elements in the code you're using the stack, the _if(!is\_full)_ statement was placed in the function itself just to guarantee that no items will be pushed to the stack, so that the _top_ indicator values doesn't get higher than the FULL_SIZE defined constant, what would cause an error and allow the stack to grow beyond its FULL_SIZE, never getting fulled.

### Pop operation

The _pop_ operation removes the last included stack element returning its value. Every time an element is droped from the stack the _top_ indicator is decremented by one and then the _items_ last item is returned by the function.

Here is the implementation of the _pop_ function in the C language:

```
int pop(stack* stk){
    stk->top--;
    return stk->items[stk->top];
}
```

> Note: because C has no exceptions to throw, it is necessary to control the dropping of elements in the code you're using the stack. In this case, no _if(!is\_empty)_ validations are needed or recommended in the function itself, because the function will return 0 (zero) as default even if there were no more items to drop. Leaving it without validation causes a _segmentation error_ which crashes the program because the _top_ indicator value gets negative when it's attempted to drop elements and there are no more elements to drop.

### Is empty operation

To check if the stack is empty (on my implementation), we just need to check if the _top_ value is euqal to 0 (zero).

Here is the implementation of the _is\_empty_ function in the C language:

```
bool is_empty(stack* stk){
    return (stk->top == 0);
}
```

### Is full operation

To check if the stack is full (on my implementation), we just need to check if the _top_ value is equal to the FULL_SIZE (1000 in this case) defined constant value.

Here is the implementation of the _is\_full_ function in the C language:

```
bool is_full(stack* stk){
    return (stk->top == FULL_SIZE);
}
```

### Length operation

The _length_ operation returns how much elements there are in the stack, (on my implementation) it just returns the value of _top_.

Here is the implementation of the _length_ function in the C language:

```
int length(stack* stk){
    return stk->top;
}
```

### Last item operation

The _last\_item_ operation just returns the last stack element's value without removing it from the stack. 

Here is the implementation of the _last\_item_ function in the C language:

```
int last_item(stack* stk){
    return stk->items[stk->top-1];
}
```

> Note: on my implementation I needed to return the _items_ array at the _top-1_ index, because the _top_ indicator was initialized as 0 (zero).


# References

[Programiz - DSA](https://www.programiz.com/dsa/stack)<br>
[Linguagem C Descomplicada](https://programacaodescomplicada.wordpress.com/indice/estrutura-de-dados/)</br>

> Note: The links referenced in this article were accessed on 2021-01-17 14:04:00 by the last time. All explanations and images used were prepared by the author himself, using as a basis the texts contained in the referred links.