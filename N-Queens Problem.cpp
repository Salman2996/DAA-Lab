#include<iostream>
#include<math.h>
using namespace std;
int board[10],count=0;
void print(int);
int place(int,int);
void queens(int row,int n)
{
	int column;
	for(column=1;column<=n;column++)
	{
		if(place(row,column))
		{
			board[row]=column;
			if(row==n)
				print(n);
			else
				queens(row+1,n);
		}
	}
}
int place(int row,int column)
{
	for(int i=1;i<=row-1;i++)
	{
		if(board[i]==column)
			return 0;
		if(fabs(board[i]-column)==fabs(i-row))
			return 0;
	}
	return 1;
}
void print(int n)
{
	cout<<"\nSolution "<<++count<<":\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(board[i]==j)
				cout<<"\tQ";
			else
				cout<<"\t-";
		}
		cout<<"\n";
	}
}
int main()
{
	int n;
	cout<<"\nEnter the number of queens: ";
	cin>>n;
	queens(1,n);
}
