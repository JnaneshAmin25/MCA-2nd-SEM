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

void push(Node*& top, int value) 
{
    Node* newNode = createNode(value);
    newNode->next = top;
    top = newNode;
    cout << "Pushed " << value << " onto the stack." << endl;
}

void pop(Node*& top) 
{
    if (top == NULL) 
	{
        cout << "Stack is empty. Cannot pop." << endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    cout << "Popped " << temp->data << " from the stack." << endl;
    delete temp;
}

bool isEmpty(Node* top) 
{
    return top == NULL;
}

void display(Node* top) 
{
    if (isEmpty(top)) 
	{
        cout << "Stack is empty." << endl;
        return;
    }
    Node* current = top;
    cout << "Stack: ";
    while (current != NULL) 
	{
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() 
{
    Node* top = NULL;
    int value, choice;
    cout << "1. Push an element onto the stack" << endl;
    cout << "2. Pop an element from the stack" << endl;
	cout << "3. Display the stack" << endl;
    cout << "4. Exit" << endl;
    do 
	{

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
		 {
            case 1:
                cout << "Enter the value to push: ";
                cin >> value;
                push(top, value);
                break;
            case 2:
                pop(top);
                break;
            case 3:
                display(top);
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

