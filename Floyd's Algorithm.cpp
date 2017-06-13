#include <iostream>
using namespace std;
int main()
{
    int a[10][10];
    int num_nodes;
    cout<<"\nEnter the order of the matrix: ";
    cin>>num_nodes;
    cout<<"\nEnter the matrix (999 for infinity) :\n";
    for(int i=0;i<num_nodes;i++)
    {
    	for(int j=0;j<num_nodes;j++)
    		cin>>a[i][j];
    }
    cout<<"\n\nWeighted Matrix:\n";
    for(int i=0;i<num_nodes;i++)
    {
    	for(int j=0;j<num_nodes;j++)
    		cout<<a[i][j]<<" ";
    	cout<<"\n";
    }
    for(int k=0;k<num_nodes;k++)
        for(int i=0;i<num_nodes;i++)
            for(int j=0;j<num_nodes;j++)
                if((a[i][k]+a[k][j])<a[i][j])
                    a[i][j] = a[i][k]+a[k][j];
    cout<<"\n\nMatrix for all pairs shortest path:\n";
    for(int i=0;i<num_nodes;i++)
    {
    	for(int j=0;j<num_nodes;j++)
    		cout<<a[i][j]<<" ";
    	cout<<"\n";
    }
}
