#include <iostream>

using namespace std;

struct Node 
{
    int data;
    Node* next;
};

Node* createNode(int value) 
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node*& head, int value) 
{
    Node* newNode = createNode(value);
    if (head == NULL || value < head->data) 
	{
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != NULL && current->next->data < value) 
	{
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void deleteNode(Node*& head, int value) 
{
    Node* temp = head;
    Node* prev = NULL;
    if (temp != NULL && temp->data == value) 
	{
        head = temp->next;
        delete temp;
        return;
    }
    while (temp != NULL && temp->data != value) 
	{
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Node with value " << value << " not found." << endl;
        return;
    }
    prev->next = temp->next;
    delete temp;
}

void displayList(Node* head) 
{
    Node* current = head;
    cout << "List: ";
    while (current != NULL) 
	{
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() 
{
    Node* head = NULL;
    int choice, value;
	cout << "1. Insert a node" << endl;
    cout << "2. Delete a node" << endl;
    cout << "3. Display the list" << endl;
    cout << "4. Exit" << endl;
    do {
        
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                insertNode(head, value);
                break;
            case 2:
                cout << "Enter the value to delete: ";
                cin >> value;
                deleteNode(head, value);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

