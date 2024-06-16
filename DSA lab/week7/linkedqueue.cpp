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

void enqueue(Node*& front, Node*& rear, int value)
 {
    Node* newNode = createNode(value);
    if (front == NULL) 
	{
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << "Enqueued " << value << " into the queue." << endl;
}

void dequeue(Node*& front, Node*& rear) 
{
    if (front == NULL) 
	{
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    }
    Node* temp = front;
    front = front->next;
    cout << "Dequeued " << temp->data << " from the queue." << endl;
    delete temp;
}

bool isEmpty(Node* front) 
{
    return front == NULL;
}

void display(Node* front)
{
    if (isEmpty(front)) 
	{
        cout << "Queue is empty." << endl;
        return;
    }
    Node* current = front;
    cout << "Queue: ";
    while (current != NULL) 
	{
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() 
{
    Node* front = NULL;
    Node* rear = NULL;
    int value, choice;
    cout << "1. Enqueue an element into the queue" << endl;
    cout << "2. Dequeue an element from the queue" << endl;
    cout << "3. Display the queue" << endl;
    cout << "4. Exit" << endl;
    do 
	{
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
                cout << "Enter the value to enqueue: ";
                cin >> value;
                enqueue(front, rear, value);
                break;
            case 2:
                dequeue(front, rear);
                break;
            case 3:
                display(front);
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

