#include <stdio.h>
#include <stdlib.h>

// Node ka structure define karna
struct Node {
    int data;              // Node ke andar ka data
    struct Node* next;     // Agle node ka pointer (link)
};

// Naya node create karne ka function
struct Node* createNode(int value) {
    // Nayi memory allocate karke node banate hain
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");  // Agar memory allocate na ho to error message
        exit(1);
    }
    newNode->data = value;     // Node mein value dalte hain
    newNode->next = NULL;      // Agla pointer NULL set karte hain (kyunki abhi next node nahi hai)
    return newNode;            // Naya node return karte hain
}

// Node ko list ke start mein insert karne ka function
void insertAtBeginning(struct Node** head, int value) {
    // Naya node banate hain
    struct Node* newNode = createNode(value);
    // Naye node ko current head ke aage link karte hain
    newNode->next = *head;
    // Naya node ab head ban jaata hai
    *head = newNode;
    printf("Inserted %d at beginning\n", value);
}

// Node ko list ke end mein insert karne ka function
void insertAtEnd(struct Node** head, int value) {
    // Naya node banate hain
    struct Node* newNode = createNode(value);
    // Agar list khali ho, to yeh naya node head ban jaayega
    if (*head == NULL) {
        *head = newNode;
        printf("Inserted %d at end (was empty)\n", value);
        return;
    }
    // Last node tak pahunchne ke liye temp ka use karte hain
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;   // Aakhri node tak iterate karte hain
    }
    temp->next = newNode;    // Last node ke 'next' ko naye node se connect karte hain
    printf("Inserted %d at end\n", value);
}

// Linked list ko print karne ka function
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");  // Agar list empty hai to message
        return;
    }
    printf("Linked List: ");
    // Head se start karke end tak list ko print karte hain
    while (head != NULL) {
        printf("%d -> ", head->data);   // Har node ka data print karte hain
        head = head->next;              // Agle node pe move karte hain
    }
    printf("NULL\n");  // End of list pe NULL print karte hain
}

// Main function
int main() {
    struct Node* head = NULL;  // Initially list khali hoti hai, head ko NULL set karte hain
    int choice, value;

    // User se input le kar insertions karenge
    printf("1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. Display list\n");
    printf("4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2: 
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);  // Program ko exit karne ke liye
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
