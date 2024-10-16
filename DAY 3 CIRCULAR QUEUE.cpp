#include <stdio.h>
#define SIZE 5 // Size of the circular queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    return (front == (rear + 1) % SIZE);
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to insert an element into the circular queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full! Cannot insert %d\n", value);
    } else {
        if (front == -1) // If the queue is empty
            front = 0;
        rear = (rear + 1) % SIZE; // Circular increment
        queue[rear] = value;
        printf("Inserted %d\n", value);
    }
}

// Function to delete an element from the circular queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Nothing to delete.\n");
    } else {
        printf("Deleted %d\n", queue[front]);
        if (front == rear) { // If there's only one element
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE; // Circular increment
        }
    }
}

// Function to display the elements of the circular queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        int i;
        printf("Queue elements: ");
        for (i = front; i != rear; i = (i + 1) % SIZE)
            printf("%d ", queue[i]);
        printf("%d\n", queue[i]); // Print the last element
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nCircular Queue Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
