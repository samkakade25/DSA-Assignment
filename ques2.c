#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

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


void display() {
    struct Node *current = head;
    if (current == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void reverse() {
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int search(int key) {
    struct Node *current = head;
    while (current != NULL) {
        if (current->data == key) {
            return 1; // Found
        }
        current = current->next;
    }
    return 0; // Not found
}

int count() {
    int count = 0;
    struct Node *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    int choice, value, key;
    do {
        printf("\nSingly Linked List Menu:\n");
        printf("1. Create List\n");
        printf("2. Reverse List\n");
        printf("3. Search Node\n");
        printf("4. Count Nodes\n");
        printf("5. Display List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                reverse();
                printf("List has been reversed.\n");
                break;
            case 3:
                printf("Enter the value to search: ");
                scanf("%d", &key);
                if (search(key)) {
                    printf("Element found in the list.\n");
                } else {
                    printf("Element not found in the list.\n");
                }
                break;
            case 4:
                printf("Number of nodes in the list: %d\n", count());
                break;
            case 5:
                display();
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
