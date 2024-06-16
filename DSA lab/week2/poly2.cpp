#include <iostream>
using namespace std;

// A utility function to return maximum of two integers
int max(int m, int n) { return (m > n) ? m : n; }

// A utility function to print a polynomial
void printPoly(int poly[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << poly[i];
        if (i != 0)
            cout << "x^" << i;
        if (i != n - 1)
            cout << " + ";
    }
}

// A utility function to add two polynomials
int* add(int A[], int B[], int m, int n, int& resultSize)
{
    int size = max(m, n);
    int* sum = new int[size];

    // Initialize the sum polynomial
    for (int i = 0; i < size; i++)
        sum[i] = 0;

    // Add coefficients of first polynomial
    for (int i = 0; i < m; i++)
        sum[i] += A[i];

    // Add coefficients of second polynomial
    for (int i = 0; i < n; i++)
        sum[i] += B[i];

    // Update the size of the result polynomial
    resultSize = size;

    return sum;
}

int main()
{
    // The following array represents polynomial 5 + 10x^2 + 6x^3
    int A[] = { 5, 0, 10, 6 };
    int m = sizeof(A) / sizeof(A[0]);

    // The following array represents polynomial 1 + 2x + 4x^2
    int B[] = { 1, 2, 4 };
    int n = sizeof(B) / sizeof(B[0]);

    cout << "First polynomial is \n";
    printPoly(A, m);

    cout << "\nSecond polynomial is \n";
    printPoly(B, n);

    int resultSize;
    int* sum = add(A, B, m, n, resultSize);

    cout << "\nSum polynomial is \n";
    printPoly(sum, resultSize);

    // Clean up memory
    delete[] sum;

    return 0;
}

