#include <iostream>

void displayPolynomial(int* coefficients, int degree) {
    for (int i = degree; i >= 0; --i) {
        if (coefficients[i] != 0) {
            if (i < degree) {
                std::cout << " + ";
            }
            std::cout << coefficients[i];
            if (i > 0) {
                std::cout << "x^" << i;
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    const int degree = 4; // Change this to the degree of your polynomial

    int coefficients[degree + 1]; // Array to store coefficients

    // Assume you have filled the coefficients array with values, or you can take input from the user
    // For example, for a quadratic polynomial 3x^2 + 2x + 1, you can set coefficients as {3, 2, 1, 0, 0}

    std::cout << "Polynomial: ";
    displayPolynomial(coefficients, degree);

    return 0;
}

