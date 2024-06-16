#include <iostream>

using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int performOperation(int operand1, int operand2, char op) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                cout << "Error: Division by zero." << endl;
                exit(1);
            }
            return operand1 / operand2;
        default:
            cout << "Error: Invalid operator." << endl;
            exit(1);
    }
}

int evaluatePrefix(const char* expression, int& index) {
    char c = expression[index--];
    if (isdigit(c)) {
        return c - '0';
    } else if (isOperator(c)) {
        int operand1 = evaluatePrefix(expression, index);
        int operand2 = evaluatePrefix(expression, index);
        return performOperation(operand1, operand2, c);
    }
    return 0; // Error handling
}

int main() {
    string prefixExpression;
    cout << "Enter a prefix expression (no spaces): ";
    cin >> prefixExpression;

    int index = prefixExpression.size() - 1;
    int result = evaluatePrefix(prefixExpression.c_str(), index);
    cout << "Result: " << result << endl;

    return 0;
}

