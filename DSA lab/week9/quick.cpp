#include <iostream>
using namespace std;

int partition(int arr[], int start, int end) {
    int pivot = arr[start];
    int pivotIndex = start;

    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot) {
            pivotIndex++;
            swap(arr[i], arr[pivotIndex]);
        }
    }
    swap(arr[start], arr[pivotIndex]);
    return pivotIndex;
}

void quickSort(int arr[], int start, int end) {
    if (start >= end)
        return;

    int p = partition(arr, start, end);

    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr; 
    return 0;
}

