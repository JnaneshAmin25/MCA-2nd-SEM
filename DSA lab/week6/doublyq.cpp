#include <iostream>
using namespace std;

#define MAX_SIZE 5

int arr[MAX_SIZE];
int front = -1;
int rear = -1;

bool isEmpty() 
{
    return front == -1 && rear == -1;
}

bool isFull() 
{
    return (rear + 1) % MAX_SIZE == front;
}

void enqueue(int data) 
{
    if (isFull()) 
	{
        cout << "Queue is full. Cannot enqueue." << endl;
        return;
    }
    if (isEmpty()) 
	{
        front = rear = 0;
    } else 
	{
        rear = (rear + 1) % MAX_SIZE;
    }
    arr[rear] = data;
}

int dequeue() 
{
    if (isEmpty()) 
	{
        cout << "Queue is empty. Cannot dequeue." << endl;
    }
    else
	{
    	int data = arr[front];
    	if (front == rear) 
		{
    	    front = rear = -1;
    	} else 
		{
        	front = (front + 1) % MAX_SIZE;
    	}
    	cout<<"dequeued:"<<data<<endl;
	}
}

int peek() 
{
    if (isEmpty()) 
	{
        cout << "Queue is empty. Cannot peek." << endl;
        return -1;
    }
    return arr[front];
}

int main() 
{
    int choice, data;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Peek" << endl;
    cout << "4. Exit" << endl;
    do 
	{

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
                cout << "Enter data to enqueue: ";
                cin >> data;
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                cout << "Front element: " << peek() << endl;
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }while(choice!=4);

    return 0;
}

