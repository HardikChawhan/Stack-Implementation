# Stack Implementation in C

This is a basic implementation of a stack data structure in C programming language. The purpose of this project is to understand how a stack works in the backend and how memory allocation is managed dynamically.

## Features

- Push elements onto the stack.
- Pop elements from the stack.
- Check the top element of the stack.
- Get the size of the stack.
- Check if the stack is empty or full.
- Swap contents of two stacks.
- Copy contents of one stack to another.
- Search for an element within the stack.
- Erase the entire stack.

## Prerequisites

- C compiler (GCC recommended)

## Usage

1. Clone the repository to your local machine:

```
git clone https://github.com/HardikChawhan/Stack-Implementation.git
```


2. Navigate to the project directory:
```
cd Stack-Implementation
```


3. Compile the code:
```
gcc stack.c -o stack
```


4. Run the executable:
```
./stack
```


## Example

### Stack Initialization
```c
    Stack myStack;
    initializeStack(&myStack, 5);

    Stack newStack;
    initializeStack(&newStack, 6);
```

### Pushing elements
```c
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    push(&myStack, 40);
    push(&myStack, 50);
```

### Stack Swapping
```c
    swap(&myStack, &newStack);
```

### Popping Elements
```c
printf("Popped from stack: %d\n", pop(&myStack));
```

### Searching
```c
search(&myStack, 3); // searching element 3 in myStack
```

### Checking Stack Empty/Full Status
```c
// Checking if stack is empty
if (isEmpty(&myStack)) {
    printf("Stack is empty\n");
} else {
    printf("Stack is not empty\n");
}

// Checking if stack is full
if (isFull(&newStack)) {
    printf("Stack is full\n");
} else {
    printf("Stack is not full\n");
}
```

### Copying Contents
```c
copy(&newStack, &destination);
```

### Erasing Stacks
```c
erase(&myStack);
erase(&newStack);
```

## License
This project is licensed under the MIT License - see the LICENSE file for details.



## Tech Stack

c (programming lanuage)




## 🔗 Links
[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/hardikchawhan)
[![twitter](https://img.shields.io/badge/twitter-1DA1F2?style=for-the-badge&logo=twitter&logoColor=white)](https://twitter.com/ChawhanHardik)

