#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void create() {
    int num, data;
    struct Node* newNode;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &num);
    
    for (int i = 0; i < num; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
        
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
}

void insert() {
    int position, data;
    struct Node* newNode;
    
    if (head == NULL) {
        printf("List is empty. Please create a list first.\n");
        return;
    }
    
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    printf("Enter the position to insert (1 for the first node): ");
    scanf("%d", &position);
    
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }
    
    printf("Enter data for the new node: ");
    scanf("%d", &data);
    
    newNode->data = data;
    
    if (position == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        struct Node* temp = head;
        for (int i = 1; i < position - 1; i++) {
            if (temp == NULL) {
                printf("Invalid position!\n");
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Node inserted successfully.\n");
}

void delete() {
    int key;
    
    if (head == NULL) {
        printf("List is empty. Please create a list first.\n");
        return;
    }
    
    printf("Enter the data to delete: ");
    scanf("%d", &key);
    
    struct Node* temp = head;
    struct Node* prev = NULL;
    
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        printf("Node with data %d deleted.\n", key);
        return;
    }
    
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Node with data %d not found.\n", key);
        return;
    }
    
    prev->next = temp->next;
    free(temp);
    printf("Node with data %d deleted.\n", key);
}

void display() {
    struct Node* temp = head;
    
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    printf("Linked List: ");
    
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                insert();
                break;
            case 3:
                delete();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

