#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

void createList() {
    int n, data;
    struct Node* newNode;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        
        if (head == NULL) {
            head = newNode;
        } else {
            struct Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    
    printf("Doubly linked list created successfully.\n");
}

void insertNode() {
    int position, data;
    struct Node* newNode;
    
    printf("Enter the position to insert a node (1 for the first node): ");
    scanf("%d", &position);
    
    if (position < 1) {
        printf("Invalid position. Please enter a positive integer.\n");
        return;
    }
    
    printf("Enter data for the new node: ");
    scanf("%d", &data);
    
    newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    
    newNode->data = data;
    
    if (position == 1) {
        newNode->next = head;
        newNode->prev = NULL;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
    } else {
        struct Node* temp = head;
        int i = 1;
        while (i < position - 1 && temp != NULL) {
            temp = temp->next;
            i++;
        }
        
        if (temp == NULL) {
            printf("Invalid position. List is not long enough.\n");
            free(newNode);
            return;
        }
        
        newNode->next = temp->next;
        newNode->prev = temp;
        
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        
        temp->next = newNode;
    }
    
    printf("Node inserted successfully.\n");
}

void deleteNode() {
    int position;
    
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    
    printf("Enter the position to delete a node (1 for the first node): ");
    scanf("%d", &position);
    
    if (position < 1) {
        printf("Invalid position. Please enter a positive integer.\n");
        return;
    }
    
    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
    } else {
        struct Node* temp = head;
        int i = 1;
        while (i < position && temp != NULL) {
            temp = temp->next;
            i++;
        }
        
        if (temp == NULL) {
            printf("Invalid position. List is not long enough.\n");
            return;
        }
        
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        
        free(temp);
    }
    
    printf("Node deleted successfully.\n");
}

void displayList() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a doubly linked list\n");
        printf("2. Insert a node\n");
        printf("3. Delete a node\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createList();
                break;
            case 2:
                insertNode();
                break;
            case 3:
                deleteNode();
                break;
            case 4:
                displayList();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    
    return 0;
}

