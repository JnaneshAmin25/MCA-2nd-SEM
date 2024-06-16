#include <iostream>

using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

      
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

       
        arr[j + 1] = key;
    }
}

void display(const int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;
    cout<<"enter the  umber of elements";
    cin>>size;
    int arr[size];
    cout<<"enter the elements:";
    for(int i = 0; i<size; i++)
	{
		cin>>arr[i];	
	}

    cout << "Array before Sorting: ";
    display(arr, size);

    insertionSort(arr, size);

    cout << "Array after Sorting: ";
    display(arr, size);

    return 0;
}

