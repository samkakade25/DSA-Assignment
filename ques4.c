#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
    }
    
    return head;
}

// Function to delete a node from the circular linked list
struct Node* deleteNode(struct Node* head, int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    
    struct Node* current = head;
    struct Node* prev = NULL;
    
    // If the node to be deleted is the head node
    if (head->data == key) {
        struct Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = head->next;
        head = head->next;
        free(current);
    } else {
        do {
            prev = current;
            current = current->next;
            if (current->data == key) {
                prev->next = current->next;
                free(current);
                break;
            }
        } while (current != head);
        
        if (current == head) {
            printf("Element %d not found in the list.\n", key);
        }
    }
    
    return head;
}

// Function to display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    
    printf("%d\n", current->data);
}

int main() {
    struct Node* head = NULL;
    int choice, data, key;

    while (1) {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at the end\n");
        printf("2. Delete a node\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insertEnd(head, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &key);
                head = deleteNode(head, key);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

