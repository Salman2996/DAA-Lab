#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main()
{
	clock_t start, end;
	double totaltime;
	int m,n;
	cout<<"\nEnter the size of the first array: ";
	cin>>m;
	cout<<"\nEnter the size of the second array: ";
	cin>>n;
	int a[m], b[n], c[m+n];
/*	cout<<"\nEnter elements of the first array:\n";
	for(int i=0;i<m;i++)
	   cin>>a[i];
	cout<<"\nEnter elements of the second array:\n";
	for(int i=0;i<n;i++)
	   cin>>b[i];  */
	for(int i=0;i<m;i++)
	   a[i]=rand();
	for(int i=0;i<n;i++)
	   b[i]=rand();
	int temp;
	start=clock();
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(b[j]>b[j+1])
			{
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}
		}
	}
	int i=0, j=0, k=0;
	while(i<n && j<m)
	{
		if(a[j]<b[i])
		{
			c[k]=a[j];
			k++;
			j++;
	    }
		else
		{
			c[k]=b[i];
			k++;
			i++;
		}
	}
	while(i<n && j>=m)
	{
		c[k]=b[i];
		k++;
		i++;
	}
	while(j<m && i>=n)
	{
		c[k]=a[j];
		k++;
		j++;
	}
	end=clock();
	totaltime=(double) ((end-start)/CLOCKS_PER_SEC);
	cout<<"\nTime taken for Merge Sort= "<<totaltime;
/*	cout<<"\nMerged array is:\n";
	for(int i=0;i<m+n;i++)
	   cout<<c[i]<<"\n";  */
}
