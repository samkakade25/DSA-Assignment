#include <iostream>

using namespace std;

// Define a singly linked list node
struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Function to create a new node and add it to the end of the list
    void createNode(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        cout << "Node with value " << value << " added to the list." << endl;
    }

    // Function to insert a new node at a specific position in the list
    void insertNode(int value, int position) {
        Node* newNode = new Node;
        newNode->data = value;

        if (position == 1) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            for (int i = 1; i < position - 1 && current != nullptr; i++) {
                current = current->next;
            }

            if (current == nullptr) {
                cout << "Invalid position." << endl;
            } else {
                newNode->next = current->next;
                current->next = newNode;
                cout << "Node with value " << value << " inserted at position " << position << "." << endl;
            }
        }
    }

    // Function to delete a node with a given value
    void deleteNode(int value) {
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr && current->data != value) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Node with value " << value << " not found in the list." << endl;
        } else {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            cout << "Node with value " << value << " deleted from the list." << endl;
        }
    }

    // Function to display the linked list
    void displayList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList myList;
    int choice, value, position;

    do {
        cout << "Linked List Menu:" << endl;
        cout << "1. Create Node" << endl;
        cout << "2. Insert Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Display List" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value for the new node: ";
                cin >> value;
                myList.createNode(value);
                break;

            case 2:
                cout << "Enter value for the new node: ";
                cin >> value;
                cout << "Enter position for insertion: ";
                cin >> position;
                myList.insertNode(value, position);
                break;

            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                myList.deleteNode(value);
                break;

            case 4:
                myList.displayList();
                break;

            case 5:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

