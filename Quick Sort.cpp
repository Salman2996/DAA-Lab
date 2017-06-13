#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int partition(int a[],int l,int r)
{
	int p=a[l];
	int i=l+1,j=r;
	int temp;
	while(i<=j)
	{
		while(a[i]<=p && i<=j)
		  i++;
		while(a[j]>p)
		  j--;
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		else
		{
			temp=a[l];
			a[l]=a[j];
			a[j]=temp;
		}
	}
	return j;
	/*int p=l, pivot=a[l],loc;
	for(loc=l+1;loc<=r;loc++)
	{
		if(pivot>a[loc])
		{
			a[p]=a[loc];
			a[loc]=a[p+1];
			a[p+1]=pivot;
			p++;
		}
	}
	return p;*/
}
void quicksort(int a[],int l,int r)
{
	int s;
	if(l<r)
	{
		s=partition(a,l,r);
		quicksort(a,l,s-1);
		quicksort(a,s+1,r);
	}
}
int main()
{
	clock_t start,end;
	double totaltime;
	int n;
	cout<<"\nEnter the size of the array: ";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	  a[i]=rand();
	start=clock();
	quicksort(a,0,n-1);
	end=clock();
	totaltime=(double) (end-start)/CLOCKS_PER_SEC;
	cout<<"\nTime taken for Quick Sort: "<<totaltime;
}
