#include <iostream>
#include <stack>
#include <algorithm> // for std::reverse

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0; // for '('
}

string reverseInfix(const string& infix) {
    string reversedInfix = infix;
    reverse(reversedInfix.begin(), reversedInfix.end());
    return reversedInfix;
}

string infixToPrefix(const string& infix) {
    // Step 1: Reverse the infix expression
    string reversedInfix = reverseInfix(infix);

    stack<char> operators;
    string postfix;

    // Step 2: Obtain the postfix expression of the reversed infix expression
    for (int i = 0; i < reversedInfix.length(); ++i) {
        char c = reversedInfix[i];

        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Pop '('
        } else if (isOperator(c)) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    // Step 3: Reverse the obtained postfix expression
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    cin >> infixExpression;

    string prefixExpression = infixToPrefix(infixExpression);

    cout << "Prefix expression: " << prefixExpression << endl;

    return 0;
}

