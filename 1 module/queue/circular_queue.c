#include <stdio.h>

#define CQ_MAX_SIZE 5 // Max size for demonstration (one slot always empty)

int circularQueue[CQ_MAX_SIZE];
int cqFront = -1;
int cqRear = -1;

// Function to enqueue an element into the circular queue
void cqEnqueue(int item) {
    if ((cqRear + 1) % CQ_MAX_SIZE == cqFront) {
        printf("Circular Queue is Full! Cannot enqueue %d\n", item);
        return;
    }
    if (cqFront == -1) { // First element
        cqFront = 0;
    }
    cqRear = (cqRear + 1) % CQ_MAX_SIZE;
    circularQueue[cqRear] = item;
    printf("%d enqueued to circular queue.\n", item);
}

// Function to dequeue an element from the circular queue
int cqDequeue() {
    if (cqFront == -1) { // Queue is empty
        printf("Circular Queue is Empty! Cannot dequeue.\n");
        return -1;
    }
    int item = circularQueue[cqFront];
    if (cqFront == cqRear) { // Last element is dequeued
        cqFront = -1;
        cqRear = -1;
    } else {
        cqFront = (cqFront + 1) % CQ_MAX_SIZE;
    }
    return item;
}

// Function to peek at the front element of the circular queue
int cqPeek() {
    if (cqFront == -1) {
        printf("Circular Queue is Empty!\n");
        return -1;
    }
    return circularQueue[cqFront];
}

// Function to check if the circular queue is empty
int cqIsEmpty() {
    return (cqFront == -1);
}

// Function to display the circular queue elements
void displayCircularQueue() {
    if (cqIsEmpty()) {
        printf("Circular Queue is empty.\n");
        return;
    }
    printf("Circular Queue elements: ");
    int i = cqFront;
    while (1) {
        printf("%d ", circularQueue[i]);
        if (i == cqRear) break;
        i = (i + 1) % CQ_MAX_SIZE;
    }
    printf("\n");
}

int main() {
    cqEnqueue(10);
    cqEnqueue(20);
    cqEnqueue(30);
    displayCircularQueue();

    printf("Dequeued element: %d\n", cqDequeue());
    displayCircularQueue();

    cqEnqueue(40);
    cqEnqueue(50);
    displayCircularQueue();

    cqEnqueue(60); // Should show full
    printf("Dequeued element: %d\n", cqDequeue());
    printf("Dequeued element: %d\n", cqDequeue());
    displayCircularQueue();
    cqEnqueue(60);
    displayCircularQueue();

    return 0;
}