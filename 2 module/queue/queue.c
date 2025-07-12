#include <stdio.h>

#define Q_MAX_SIZE 50 // Maximum size of the queue

int simpleQueue[Q_MAX_SIZE];
int front = -1;
int rear = -1;

// Function to add an element to the queue (enqueue)
void enqueue(int item) {
    if (rear == Q_MAX_SIZE - 1) {
        printf("Queue is Full! Cannot enqueue %d\n", item);
        return;
    }
    if (front == -1) { // If it's the first element
        front = 0;
    }
    simpleQueue[++rear] = item;
    printf("%d enqueued to queue.\n", item);
}

// Function to remove an element from the queue (dequeue)
int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty! Cannot dequeue.\n");
        return -1; // Indicate error
    }
    int item = simpleQueue[front++];
    if (front > rear) { // If queue becomes empty after dequeue
        front = -1;
        rear = -1;
    }
    return item;
}

// Function to peek at the front element of the queue
int qFront() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty!\n");
        return -1;
    }
    return simpleQueue[front];
}

// Function to check if the simple queue is empty
int qIsEmpty() {
    return (front == -1);
}

// Function to display the simple queue elements
void displaySimpleQueue() {
    if (qIsEmpty()) {
        printf("Simple Queue is empty.\n");
        return;
    }
    printf("Simple Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", simpleQueue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    displaySimpleQueue();

    printf("Dequeued element: %d\n", dequeue());
    displaySimpleQueue();

    printf("Front element: %d\n", qFront());
    printf("Is queue empty? %s\n", qIsEmpty() ? "Yes" : "No");

    return 0;
}