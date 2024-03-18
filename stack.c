// project 1 - Implementing Stack from scratch
// objective - understanding how stack works in backend and how memory gets allocated dynamically

// -1 indicates stack an empty stack

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Stack implementation
typedef struct {
    int *data;
    int top;
    int capacity; // represents the maximum size
} Stack;

// initialize an empty stack. needs to be called before adding elements
void initializeStack(Stack *stack, int capacity) {
    stack->data = (int *)malloc(capacity * sizeof(int)); // dynamically allocates memory
    if (stack->data == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    stack->top = -1;
    stack->capacity = capacity;
}

// pushes the elements at the end since it is a stack
void push(Stack *stack, int element) {
    if (stack->top == stack->capacity - 1)
    { // checks for stack overflow
        printf("Stack overflow! cannot push %d\n", element);
        return;
    }
    stack->data[++stack->top] = element;
}

// pops/removes the last element from the stack. since it is a stack
int pop(Stack *stack) {
    if (stack->top == -1)
    {
        // checks for stack underflow
        printf("Stack underflow\n");
        return -1; // Assuming -1 as an invalid value for this example
    }
    return stack->data[stack->top--];
}

// function to print the stack
void printStack(Stack *stack) {
    if (stack->top == -1)
    {
        printf("\nStack is empty\n");
        return;
    }
    else
    {
        for (int i = 0; i <= stack->top; i++)
        {
            printf("%d ", stack->data[i]);
        }
        printf("\n");
    }
}

// function to erase the entire stack
void erase(Stack *stack) {
    if (stack->top == -1)
    {
        printf("\nStack is already empty\n");
        return;
    }
    else
    {
        free(stack->data);
        stack->data = NULL;
        stack->top = -1;
        stack->capacity = 0;
    }
}

// returns top/last element of the stack
int top(Stack *stack) {
    if (stack->top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        return stack->data[stack->top];
    }
}

// returns the size of the stack
int size(Stack *stack) {
    if (stack->top == -1)
    {
        // stack is empty
        return -1; // this value can be changed
    }
    else
    {
        return stack->top + 1;
    }
}

// swaps 2 stacks
void swap(Stack *stack1, Stack *stack2) {
    if (stack1->top == -1 && stack2->top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        int size1 = size(stack1);
        int size2 = size(stack2);
        int minSize = (size1 < size2 ? size1 : size2);
        for (int i = 0; i < minSize; i++)
        {
            int temp = stack1->data[i];
            stack1->data[i] = stack2->data[i];
            stack2->data[i] = temp;
        }
    }
}

// creates a new stack and copies the contents of an existing stack into the new one
void copy(Stack *source, Stack *destination){
    erase(destination);

    if (source->capacity > destination->capacity)
    {
        // reallocates the memory if source and destination does not have same size 
        destination->data = (int*)realloc(destination->data , source->capacity * sizeof(int));
        if (destination->data == NULL)
        {
            printf("memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        destination->capacity = source->capacity;
    }
    
    for (int i = 0; i <=source->top; i++)
    {
        push(destination,source->data[i]);
    }
}

// uses liner search algorithm to search the given element in the stack
int search(Stack *stack, int element){
    if (stack->top == -1)
    {
        printf("stack is empty\n");
        return -1;
    }
    else{
        for (int i = 0; i <=stack->top; i++)
        {
            if (stack->data[i] == element)
            {
                return i;
            }
        }
        printf("%d is not present in the stack\n",element);
        return -1; // element not found
    }
}

// checks if the stack is empty or not
bool isEmpty(Stack *stack) {
    return (stack->top == -1)?true : false;
}

// checks if the stack is full or not
bool isFull(Stack *stack){
    return (stack->top == stack->capacity-1)?true : false;
}

// driver code
int main() {
    // Example usage
    Stack myStack;
    Stack newStack;
    Stack destination;
    initializeStack(&myStack, 5);
    initializeStack(&newStack, 6);
    initializeStack(&destination,1);
    

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    push(&myStack, 40);
    push(&myStack, 50);
    push(&myStack, 60); // this is not possible since maximum size of stack is reached

    // adding elements to the newStack 
    for (int i = 0; i < 6; i++)
    {
        push(&newStack, i + 1);
    }

    printStack(&myStack);
    printStack(&newStack);

    printf("The last element is : %d\n", top(&myStack));

    printf("The size of the myStack is : %d\n", size(&myStack));
    printf("The size of the newStack is : %d\n", size(&newStack));

    swap(&myStack, &newStack);
    
    // after swaping the stack
    printStack(&myStack);
    printStack(&newStack);

    printf("Popped from stack: %d\n", pop(&myStack));
    printf("Popped from stack: %d\n", pop(&myStack));

    printStack(&myStack);

    int element = search(&myStack,3); // searching element 3 in myStack
    printf("the element is at index %d\n",element);

    // to check if the stack is empty
    if (isEmpty(&myStack))
    {
        printf("stack is empty\n");
    }
    else{
        printf("stack is not empty\n");
    }

    // to check if the stack is full
    if (isFull(&newStack))
    {
        printf("stack is full\n");
    }
    else{
        printf("stack is not full\n");
    }

    push(&destination,100);
    copy(&newStack,&destination);
    printStack(&destination);
    
    erase(&myStack);
    printStack(&myStack);

    erase(&newStack);
    erase(&destination);

    return 0;
}
