#include<iostream>
using namespace std;

int main() {
    int num_elements;
    cout << "Enter the number of elements: ";
    cin >> num_elements;

    int a[num_elements];

    cout << "Enter " << num_elements << " integers:\n";
    for (int i = 0; i < num_elements; i++) {
        cin >> a[i];
    }

    cout << "Input list ...\n";
    for (int i = 0; i < num_elements; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;

    int temp, pass = 0;
    for (int i = 0; i < num_elements; i++) {
        for (int j = i + 1; j < num_elements; j++) {
            if (a[j] < a[i]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        pass++;
    }

    cout << "Sorted Element List ...\n";
    for (int i = 0; i < num_elements; i++) {
        cout << a[i] << "\t";
    }
    cout << "\nNumber of passes taken to sort the list: " << pass << endl;
    
    return 0;
}

