#include<bits/stdc++.h>
using namespace std;
vector<int>adj[10001];
int visited[10001];
void DFS(int node)
{
	visited[node]=1;
	for(auto i:adj[node])
	{
		if(!visited[i])
		{
			DFS(i);
			visited[i]=1;
		}
	}
}
int main()
{
	int vertices,edges;
	cin>>vertices>>edges;
	int i,c=0;
	for(i=0; i<vertices; i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(i=1; i<vertices; i++)
	{
		if(!visited[i])
		{
			DFS(i);
			c++;
		}
	}
	cout<<c<<endl;
}