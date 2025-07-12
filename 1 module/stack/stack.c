#include <stdio.h>
#include <stdlib.h> //for exit

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1; //initialize top of the stack

//function to push elements onto the stack
void push(int item) {
    if (top >= MAX_SIZE-1) {
        printf("Stack Overflow! canont push %d\n", item);
        return;
    }
    stack[++top] = item;
    printf("Pushed %d onto stack\n", item);
}

//function to pop elements from the stack
int pop() {
    if (top < 0) {
        printf("Stack is Empty! cannot pop\n");
        return -1;
    }
    return stack[top--];
}

//function to peek at the top element of the stack
int peek() {
    if (top < 0) {
        printf("Stack is Empty! cannot peek\n");
        return -1;
    }
    return stack[top];
}

//function to check if the stack is empty
int isEmpty() {
    return (top == -1);
}

//function to check if stack is full
int isFull() {
    return (top == MAX_SIZE - 1);
}

//function to display stack elements
void display() {
    if (isEmpty()) {
        printf("Stack is Empty!\n");
        return; 
    }
    printf("stack elements are: ");
    for (int i = top; i >= 0; i--) {
        printf("%d \n", stack[i]);
    }
    printf("\n");
}

//main function
int main() {
    int choice, item;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check if Empty\n");
        printf("6. Check if Full\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                item = pop();
                if (item != -1) {
                    printf("Popped %d from stack\n", item);
                }
                break;
            case 3:
                item = peek();
                if (item != -1) {
                    printf("Top element is %d\n", item);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                if (isEmpty()) {
                    printf("Stack is Empty.\n");
                } else {
                    printf("Stack is not Empty.\n");
                }
                break;
            case 6:
                if (isFull()) {
                    printf("Stack is Full.\n");
                } else {
                    printf("Stack is not Full.\n");
                }
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}