#include<iostream>
using namespace std;
int main()
{
	int arr[20][20],i,j,row,column,nonZero=0;
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
			if(arr[i][j]!=0)
			{
				nonZero++;	
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
	

	cout<<"\n\nROW   COLUMN   VALUE:\n-------------------------------------------\n";
	cout<<row<<"\t"<<column<<"\t"<<nonZero<<"\n";
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
		 if(arr[i][j]!=0)
		 {
		 	cout<<i<<"\t"<<j<<"\t"<<arr[i][j];
		 	cout<<"\n";
		 }
		}
	}
	return 0;
}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

