#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(NULL), next(NULL) {}
};

Node* head = NULL;

void insert(int value, bool insertAtFront) {
    Node* newNode = new Node(value);

    if (insertAtFront || head == NULL || value < head->data) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }

        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) {
            current->next->prev = newNode;
        }

        current->next = newNode;
    }

    cout << "Node with value " << value << " inserted at " << (insertAtFront ? "front" : "back") << ".\n";
}

void remove(int value) {
    Node* current = head;

    while (current != NULL && current->data != value) {
        current = current->next;
    }

    if (current == NULL) {
        cout << "Node with value " << value << " not found.\n";
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    delete current;
    cout << "Node with value " << value << " deleted "  << ".\n";
}

void display() {
    Node* current = head;

    cout << "Forward direction: ";
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    current = head;

    cout << "Reverse direction: ";
    while (current != NULL && current->next != NULL) {
        current = current->next;
    }

    while (current != NULL) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}

int main() {
    int choice, value;
    bool insertAtFront;
	cout << "---- MENU ----\n";
    cout << "1. Insert a node\n2. Delete a node\n3. Display list\n4. Exit\n";
    do {
        
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                cout << "Insert at front? (1 for yes, 0 for no): ";
                cin >> insertAtFront;
                insert(value, insertAtFront);
                break;
            case 2:
                cout << "Enter the value to delete: ";
                cin >> value;
                remove(value);
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4);

    return 0;
}

