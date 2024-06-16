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
    newNode->next = head;
    head = newNode;
}

void displayList(Node* head) 
{
    Node* current = head;
    while (current != NULL) 
	{
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

Node* reverseList(Node* head) 
{
    if (head == NULL || head->next == NULL) 
	{
        return head;
    }
    Node* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

int main() 
{
    Node* head = NULL;
    int value;

    cout << "Enter the number of nodes: ";
    int n;
    cin >> n;

    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; ++i) 
	{
        cin >> value;
        insertNode(head, value);
    }

    cout << "\nOriginal List: ";
    displayList(head);

    head = reverseList(head);

    cout << "\nReversed List: ";
    displayList(head);

    return 0;
}

