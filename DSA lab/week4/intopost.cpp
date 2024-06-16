#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

bool isOperator(char c) 
{
    return (c == '+' || c == '-' || c == '*' || c == '/'|| c=='^');
}

int precedence(char op)
 {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if(op == '^')
    	return 3;
    return 0; 
}

string infixToPostfix(const string& infix)
 {
    stack<char> stack;
    string postfix;
    

    for (int i = 0; i < infix.length(); ++i)
	 {
        char c = infix[i];

        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') 
		{
            while (!stack.empty() && stack.top() != '(')
			 {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop(); // Pop '('
        } 		
		
		else if (isOperator(c)) {
            while (!stack.empty() && precedence(stack.top()) >= precedence(c)) 
			{
                postfix += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.empty())
	 {
        postfix += stack.top();
        stack.pop();
    }

    return postfix;
}

int main()
 {
    string infixExpression;
    cout << "Enter an infix expression: ";
    cin >> infixExpression;

    string postfixExpression = infixToPostfix(infixExpression);

    cout << "Postfix expression: " << postfixExpression << endl;

    return 0;
}

