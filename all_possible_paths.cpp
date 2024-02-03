#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1000005];
int visited[1000005];
void dfs(int s,int d,vector<int>&l)
{
	if(s==d)
	{
		for(auto i:l)
		{
			cout<<i<<" ";
		}
		cout<<endl;
		return;
	}
	visited[s]=1;
	for(auto i:adj[s])
	{
		if(!visited[i])
		{
			l.push_back(i);
			dfs(i,d,l);
			l.pop_back();
		}
	}
	visited[s]=0;
}
int main()
{
	int vertices,edges,i;
	cin>>vertices>>edges;
	for(i=0; i<edges; i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	for(i=1; i<=vertices; i++)
	{
		vector<int>l;
		l.push_back(i);
		dfs(i,4,l);
		cout<<endl;
	}
}
