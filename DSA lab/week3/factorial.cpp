#include <iostream>
using namespace std;
int factorial(int n)
 {
    if (n == 0)
	{
        return 1;
    }
    return n * factorial(n - 1);
}

int main() 
{
    int num;
    cout << "Enter a non-negative integer: ";
    cin >> num;
    if (num < 0) 
	{
        cout << "Please enter a non-negative integer." <<endl;
        return 1; 
    }
    int result = factorial(num);
    cout << "Factorial of " << num << " = " << result <<endl;
    return 0;
}

