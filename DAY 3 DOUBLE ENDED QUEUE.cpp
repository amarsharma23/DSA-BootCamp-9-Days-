#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // SIZE ka matlab hai queue ka maximum size kitna hai

// Deque structure define kar rahe hain, jo items store karega aur front aur rear pointers honge
struct Deque {
    int items[SIZE];
    int front, rear;
};

// Deque ko initialize karna (starting position set karna)
void initDeque(struct Deque* dq) {
    dq->front = -1;  // Front -1 se set, queue khali hai
    dq->rear = -1;   // Rear bhi -1 pe set, queue empty hai
}

// Check karna ki deque full hai ya nahi
int isFull(struct Deque* dq) {
    // Queue full tab hoti hai jab ya toh front rear ke ek step aage ho ya queue ka last item aur pehle item fill ho
    return ((dq->front == (dq->rear + 1) % SIZE) || (dq->front == 0 && dq->rear == SIZE - 1));
}

// Check karna ki deque empty hai ya nahi
int isEmpty(struct Deque* dq) {
    // Agar front -1 pe hai to queue khali hai
    return (dq->front == -1);
}

// Rear se insert karna
void insertRear(struct Deque* dq, int value) {
    if (isFull(dq)) {  // Pehle check karenge ki queue full hai ya nahi
        printf("Deque is full!\n");
        return;
    }
    if (isEmpty(dq)) {  // Agar empty hai toh front aur rear dono ko 0 pe set karenge
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % SIZE;  // Rear ko circular tarike se badha rahe hain
    }
    dq->items[dq->rear] = value;  // Value insert karna rear position pe
    printf("Inserted %d at rear\n", value);
}

// Front se insert karna
void insertFront(struct Deque* dq, int value) {
    if (isFull(dq)) {  // Pehle check karenge ki queue full hai ya nahi
        printf("Deque is full!\n");
        return;
    }
    if (isEmpty(dq)) {  // Agar queue empty hai toh front aur rear dono ko 0 pe set karenge
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + SIZE) % SIZE;  // Front ko circular way se piche le ja rahe hain
    }
    dq->items[dq->front] = value;  // Value ko front pe insert karenge
    printf("Inserted %d at front\n", value);
}

// Front se delete karna
void deleteFront(struct Deque* dq) {
    if (isEmpty(dq)) {  // Agar queue khali hai toh delete nahi kar sakte
        printf("Deque is empty!\n");
        return;
    }
    printf("Deleted %d from front\n", dq->items[dq->front]);  // Front se value delete karenge
    if (dq->front == dq->rear) {  // Agar front aur rear same position pe hai, queue khali ho gayi hai
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % SIZE;  // Front ko circular way se aage badha rahe hain
    }
}

// Rear se delete karna
void deleteRear(struct Deque* dq) {
    if (isEmpty(dq)) {  // Agar queue khali hai toh delete nahi kar sakte
        printf("Deque is empty !\n");
        return;
    }
    printf("Deleted %d from rear\n", dq->items[dq->rear]);  // Rear se value delete karenge
    if (dq->front == dq->rear) {  // Agar front aur rear ek hi jagah pe hai, queue empty ho gayi hai
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + SIZE) % SIZE;  // Rear ko circular way se piche le ja rahe hain
    }
}

// Deque ke elements ko display karna
void displayDeque(struct Deque* dq) {
    if (isEmpty(dq)) {  // Agar queue empty hai toh display nahi kar sakte
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque elements: ");
    int i = dq->front;  // Front se start karke print karenge
    while (i != dq->rear) {  // Jab tak rear pe nahi pahunche tab tak print karte rahenge
        printf("%d ", dq->items[i]);
        i = (i + 1) % SIZE;  // Circular increment karna
    }
    printf("%d\n", dq->items[dq->rear]);  // Last element ko print karenge
}

// Main function jahan se user input le kar operations perform karenge
int main() {
    struct Deque dq;
    initDeque(&dq);  // Deque initialize kar rahe hain

    int choice, value;
    while (1) {  // Infinite loop taki bar bar user input le sakein
        printf("\nDouble-Ended Queue Operations:\n");
        printf("1. Insert at rear\n");
        printf("2. Insert at front\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Display deque\n");
        printf("6. Exit\n");
        printf("ENTER YOUR CHOICES : ");
        scanf("%d", &choice);  // User se choice le rahe hain

        switch (choice) {
            case 1:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);  // Value input kar rahe hain
                insertRear(&dq, value);  // Rear se insert kar rahe hain
                break;
            case 2:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);  // Value input kar rahe hain
                insertFront(&dq, value);  // Front se insert kar rahe hain
                break;
            case 3:
                deleteFront(&dq);  // Front se delete kar rahe hain
                break;
            case 4:
                deleteRear(&dq);  // Rear se delete kar rahe hain
                break;
            case 5:
                displayDeque(&dq);  // Deque ko display kar rahe hain
                break;
            case 6:
                exit(0);  // Program se exit kar rahe hain
            default:
                printf("Invalid choice, try again.\n");  // Agar choice invalid ho toh message dikhayenge
        }
    }

    return 0;
}
