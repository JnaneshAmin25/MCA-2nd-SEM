#include <iostream>

using namespace std;

bool isOperator(char c) 
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}


int evaluatePostfix(const string& expression) 
{
    int operandStack[100];  
    int top = -1; 

    for (int i = 0; i < expression.size(); ++i) 
	{
        char c = expression[i];
        if (isdigit(c)) 
		{
            operandStack[++top] = c - '0';
        } else if (isOperator(c)) 
		{
            int operand2 = operandStack[top--];
            int operand1 = operandStack[top--];

            switch (c) 
			{
                case '+':
                    operandStack[++top] = operand1 + operand2;
                    break;
                case '-':
                    operandStack[++top] = operand1 - operand2;
                    break;
                case '*':
                    operandStack[++top] = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) 
					{
                        cout << "Error: Division by zero." << endl;
                        exit(1);
                    }
                    operandStack[++top] = operand1 / operand2;
                    break;
                default:
                    cout << "Error: Invalid operator." << endl;
                    exit(1);
            }
        }
    }

    return operandStack[top];
}

int main() 
{
    string postfixExpression;
    cout << "Enter a postfix expression (no spaces): ";
    cin >> postfixExpression;

    int result = evaluatePostfix(postfixExpression);
    cout << "Result: " << result << endl;

    return 0;
}

