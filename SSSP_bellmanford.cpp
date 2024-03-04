#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> bellmanford(vector<vector<ll>>&adj,int scr,int v)
{
	vector<ll>distances(v,INT_MAX);
	distances[scr]=0;
	int j;
	for(j=0; j<v-1; j++)
	{
		for(auto i:adj)
		{
			int u=i[0],v=i[1],wt=i[2];
			if(distances[u]!=INT_MAX and distances[u]+wt<distances[v])
			{
				distances[v]=distances[u]+wt;
			}
		}
	}
	for(j=0; j<v-1; j++)
	{
		for(auto i:adj)
		{
			int u=i[0],v=i[1],wt=i[2];
			if(distances[u]!=INT_MAX and distances[u]+wt < distances[v])
			{
				cout<<"Negetive cycle exists";
				exit(0);
			}
		}
	}
	return distances;
}
int main()
{
	int vertices,edges,i,u,v,wt;
	cin>>vertices>>edges;
	vector<vector<ll>>adj;
	for(i=0; i<edges; i++)
	{
		cin>>u>>v>>wt;
		adj.push_back({u,v,wt});
	}
	int src;
	cin>>src;
	vector<ll>res=bellmanford(adj,src,vertices);
	for(auto i:res)
	{
		cout<<i<<" ";
	}
}
