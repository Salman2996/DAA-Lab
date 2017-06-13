#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
void heapify(int h[],int n)
{
	int i,j,n1,k,heap,v;
	n1=n;
	for(i=n1/2;i>=1;i--)
	{
		k=i;
		v=h[k];
		heap=0;
		while(!(heap)&&(2*k)<=n1)
		{
			j=2*k;
			if(j<n1)
				if(h[j]<h[j+1])
					j=j+1;
			if(v>=h[j])
				heap=1;
			else
			{
				h[k]=h[j];
				k=j;
			}
		h[k]=v;
		}
	}
}
int main()
{
	int i,n,size,t;
	clock_t start,end;
	double totaltime;
	cout<<"\nEnter value of n: ";
	cin>>n;
	int h[n];
	for(i=1;i<=n;i++)
		h[i]=rand();
	/*cout<<"\nElements are:\n";
	for(i=1;i<=n;i++)
		cout<<h[i]<<"\n";*/
	start=clock();
	heapify(h,n);
	/*cout<<"\nHeapified elements are:\n";
	for(i=1;i<=n;i++)
		cout<<h[i]<<"\n";*/
	for(i=n;i>=1;i--)
	{
		t=h[1];
		h[1]=h[i];
		h[i]=t;
		size=i-1;
		heapify(h,size);
	}
	end=clock();
	/*cout<<"\nSorted elements are:\n";
	for(i=1;i<=n;i++)
		cout<<h[i]<<"\n";*/
	totaltime=(double)(end-start)/CLOCKS_PER_SEC;
	cout<<"\nTime taken: "<<totaltime;
}
