#include<iostream>
using namespace std;

struct sparse
{
    int row, column, value;
};

int main()
{
    int row, column, nonZero = 0;
    
    cout << "enter the number of rows : ";
    cin >> row;
    
    cout << "enter the number of columns : ";
    cin >> column;
    
   
    int spar[20][20];
    
    cout << "enter the elements :\n ";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)  
        {
            cin >> spar[i][j];
            if (spar[i][j] != 0)
            {
                nonZero++;
            }
        }
    }


    sparse *s = new sparse[nonZero];

    cout << "entered matrix is\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << spar[i][j] << " ";
        }
        cout << endl;
    }

    int sparcheck = (row * column) / 2;
    if (nonZero > sparcheck)
    {
        cout << "not a sparse matrix: number of zeros should be more than the number of non-zero elements";
    }


    delete[] s;

    return 0;
}

