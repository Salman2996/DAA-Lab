#include<iostream>
using namespace std;
int main()
{
    int num_nodes;
    int adj[10][10];
    cout<<"\nEnter the order of the adjacency matrix: ";
    cin>>num_nodes;
    cout<<"\nEnter the adjacency matrix of the graph:\n";
    for(int i=0;i<num_nodes;i++)
    {
    	for(int j=0;j<num_nodes;j++)
    		cin>>adj[i][j];
    }
    cout<<"\n\nAdjacency matrix:\n";
    for(int i=0;i<num_nodes;i++)
    {
        for(int j=0;j<num_nodes;j++)
            cout<<adj[i][j]<<" ";
        cout<<"\n";
    }
    for(int k=0;k<num_nodes;k++)
        for(int i=0;i<num_nodes;i++)
                for(int j=0;j<num_nodes;j++)
                    adj[i][j]=adj[i][j] || (adj[i][k] && adj[k][j]);
    cout <<"\n\nTransitive Closure of the Graph:\n";
    for(int i=0;i<num_nodes;i++)
    {
        for(int j=0;j<num_nodes;j++)
            cout<<adj[i][j]<<" ";
        cout<<"\n";
    }
}
