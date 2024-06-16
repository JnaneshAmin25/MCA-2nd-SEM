#include <iostream>

const int MAX_SIZE = 100;

struct Sparse {
    int row;
    int column;
    int value;
};

void convertToTriplet(int originalMatrix[][MAX_SIZE], Sparse sparseMatrix[], int& numNonZero, int numRows, int numCols) {
    numNonZero = 0;

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (originalMatrix[i][j] != 0) {
                sparseMatrix[numNonZero].row = i;
                sparseMatrix[numNonZero].column = j;
                sparseMatrix[numNonZero].value = originalMatrix[i][j];
                ++numNonZero;
            }
        }
    }
}

int main() {
    int numRows, numCols;
    int originalMatrix[MAX_SIZE][MAX_SIZE];

    // Input the number of rows and columns
    std::cout << "Enter the number of rows: ";
    std::cin >> numRows;
    std::cout << "Enter the number of columns: ";
    std::cin >> numCols;

    // Input matrix elements
    std::cout << "Enter the matrix elements:" << std::endl;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            std::cout << "Enter element at position (" << i << ", " << j << "): ";
            std::cin >> originalMatrix[i][j];
        }
    }

    // Convert to triplet form
    Sparse sparseMatrix[MAX_SIZE * MAX_SIZE];
    int numNonZero;

    convertToTriplet(originalMatrix, sparseMatrix, numNonZero, numRows, numCols);

    // Print the triplet form
    std::cout << "Triplet form (row, column, value):" << std::endl;
    for (int i = 0; i < numNonZero; ++i) {
        std::cout << "(" << sparseMatrix[i].row << ", " << sparseMatrix[i].column << ", " << sparseMatrix[i].value << ")" << std::endl;
    }

    return 0;
}

