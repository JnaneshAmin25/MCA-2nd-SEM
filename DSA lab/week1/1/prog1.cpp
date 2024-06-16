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
			cin>>arr[i][j];
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
	

	cout<<"\n\n ROW MAJOR REPRESENTATION:\n[";
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
		 cout<<arr[i][j];
		 cout<<"\t";
		}
	}
	cout<<"]";
	
	cout<<"\n\n COLUMN MAJOR REPRESENTATION:\n [";
	for(j=0;j<column;j++)
	{
		for(i=0;i<row;i++)
		{
		 cout<<arr[i][j];
		 cout<<"\t";
		}
	}
	cout<<"]";
	
	cout<<"\nenter the location of the element:";
	cin>>i>>j;
	cout<<"\nthe element in that location is: ";
	cout<<arr[i][j];
	int rowlen = column;
	int collen = row;
	cout<<"\noffset for row-major:";
	int offset = (i*rowlen)+j;
	cout<<offset<<endl;
	cout<<"\noffset for col-major:";
	offset = (j*collen)+i;
	cout<<offset;
	return 0;
}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

