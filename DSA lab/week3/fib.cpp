#include <iostream>

using namespace std;

int fibonacci(int n)
{
    if (n==0)
        return 0;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
	cout<<"enter the number:";
    cin >> n;

    for (int i = 0; i <n; ++i) {
        cout << fibonacci(i) << " ";
    }

    return 0;
}

