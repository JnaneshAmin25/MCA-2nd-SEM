#include<iostream>
using namespace std;
int main()
{
	int arr[20][20],i,j,row,column;
	cout<<"enter the number of rows:";
	cin>>row;
	cout<<"\n enter the number of columns:";
	cin>>column;
	
	cout<<"\nenter the elements:";
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			if(i==j)
			{
				cin>>arr[i][j];
			}
			else
			{
				arr[i][j] = 0;
			}
		}
	}
	cout<<"\nentered array is:\n";
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			cout<<arr[i][j];
			cout<<"\t";
		}
		cout<<"\n";
	}
	

	cout<<"\n\n 1D ARRAY REPRESENTATION OF DIAGONAL MATRIX:\n[";
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
		 if(i==j)
		 {
		 	cout<<arr[i][j];
		 	cout<<"\t";
		 }
		}
	}
	cout<<"]";

	
	cout<<"\nenter the location of the element:";
	cin>>i>>j;
	cout<<"\nthe element in that location is: ";
	cout<<arr[i][j];
	if(arr[i][j]==0)
	{
		cout<<"\ninvalid location";
	}
	else
	{
		int rowlen = column;
		int collen = row;
		cout<<"\noffset for diagonal matrix:";
		int offset = (i*rowlen)+j;
		cout<<offset<<endl;
		return 0;
	}
}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

