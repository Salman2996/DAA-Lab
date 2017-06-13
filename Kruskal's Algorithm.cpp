#include<iostream>
using namespace std;
int main()
{
	int n,i,j,min,cost[20][20],a,u,b,v,parent[20];
	int ne=1,min_cost=0;
	cout<<"\nEnter the number of nodes: ";
	cin>>n;
	cout<<"\nEnter the cost matrix:\n";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			cin>>cost[i][j];
	}
	for(i=1;i<=n;i++)
		parent[i]=0;
	cout<<"\nMinimum cost spanning tree:\n";
	while(ne<n)
	{
		min=999;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		while(parent[u])
			u=parent[u];
		while(parent[v])
			v=parent[v];
		if(u!=v)
		{
			cout<<"\nEdge "<<ne++<<" ("<<a<<"->"<<b<<")= "<<min;
			min_cost+=min;
			parent[v]=u;
		}
		cost[a][b]=cost[a][b]=999;
	}
	cout<<"\nMinimum cost= "<<min_cost;
}
